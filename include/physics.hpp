#include <vector>


#ifndef PHYSICS_HPP
#define PHYSICS_HPP

/*! \brief Datatype to store position of a starling*/ 
class position{
public:
	/// x-coordinate
	float x;

	/// y-coordinate
	float y;

	/// z-coordinate
	float z;

	position();

	position operator+(const position &param);

	position operator-(const position &param);

	position operator/(const float &c);

	position operator*(const float &c);
};

/*! \brief Datatype to store velocity of a starling*/ 
class velocity{
public:
	/// Velocity in x-direction
	float v_x;
	
	/// Velocity in y-direction
	float v_y;

	/// Velocity in z-direction
	float v_z;

	velocity();
	
	velocity operator+(const velocity &param);

	velocity operator-(const velocity &param);

	velocity operator/(const float &c);

	velocity operator*(const float &c);

};

/*! \brief Datatype to store starling data*/ 
class starling{
public:
	/// Position of the starling at an instance and previous instance
	position pos_old, pos_new;

	/// Velocity of the starling at an instance and previous instance
	velocity v_old, v_new;

	/// Index of neighbours of starling in starling list
	std::vector<int> neighbours;

	/// Mechanical energy of boid at the previous time_step
	float E_mech_old, E_mech_new;

	/// Energy stored (muscle energy) with an starling at an instance
	float E_str_old, E_str_new;

	/** Finds the neighbours of the starling
	* @param[in] murmuration List of all starlings
	*/
	void get_neighbours(std::vector<starling> &murmuration);

	/** Finds the velocity update from the "Cohesion" rule
	*   @return Change in velocity due to the rule 
	*/
	velocity cohesion_update(std::vector<starling> &murmuration);

	/** Finds the velocity update from the "Separation" rule
	*   @return Change in velocity due to the rule 
	*/
	velocity separation_update(std::vector<starling> &murmuration);

	/** Finds the velocity update from the "Alignment" rule
	*   @return Change in velocity due to the rule 
	*/
	velocity alignment_update(std::vector<starling> &murmuration);

	/** Update velocity using the three base rules
	*/
	void update_velocity(std::vector<starling> &murmuration);

	/** Update position based on the velocity at an instance
	*/
	void update_position(float time_step);

	/** Update the energy stored(muscle energy) with the starling after change in velocity and position
	*	Update only performed if the energy stored is more than some specified limit
	*/
	void update_stored_energy(void);

	/** Update the velocity of based on energy stored
	*	If the stored energy is less than a specified constant, increase the stored energy by decreasing the mechanical energy at the present instance
	*/
	void update_velocity_from_energy(void);

};


#endif