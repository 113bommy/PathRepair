def build_ball_dictionary(ball_arrangement):
    """
    Helper function for 'compute_ways_2_eliminate_all_balls' that builds a
    dictionary that maps the starting position of a ball to a list that
    contains the color of the ball as well as 1 + the number of balls of the
    same color that follow it.
    This function only needs to be called once.

    Input:
    ball_arrangement : <str>
    # Contains arrangement of original row of balls

    # Output :
    ball_dictionary : < <int> : <str, int> >
    Dictionary that maps the starting position of a ball to a list that
    contains the color of the ball as well as 1 + the number of balls of the
    same color that follow consecutively.

    num_unique_colors : int
    Represents the number of unique colors found in the initial set of balls
    """

    # Initialize dictionary object
    ball_dictionary = {}
    # Initialize list object
    unique_ball_colors_list = []

    # Initialize counter that points to a location in the string representing
    # the initial set of balls
    index = 0
    # Get number of balls at game's outset
    n_balls = len(ball_arrangement)
    while index < n_balls:
        # Get the color of the ball at location 'index' in the
        # ball_arrangement variable
        current_ball_color = ball_arrangement[index]

        # Reset length of current ball segment that contains all balls of
        # the same color
        current_segment_length = 1

        # If ball color has not yet been encountered, add to list tracking
        # unique ball colors
        if current_ball_color not in unique_ball_colors_list:
            unique_ball_colors_list.append(current_ball_color)

        # Continue extending search towards the end of the original string
        # until a new ball color is found. However, if we are at the end of
        # the string, then there is no need to extend search (unless we want
        # an 'index out of bounds' exception error)
        while index < n_balls and index+current_segment_length < n_balls \
              and ball_arrangement[index + current_segment_length] == \
                  current_ball_color:

            current_segment_length += 1

        ball_dictionary[index] = [current_ball_color, current_segment_length]
        index += current_segment_length

    # Get number of unique colors in row of balls
    num_unique_colors = len(unique_ball_colors_list)

    return ball_dictionary, num_unique_colors


def compute_ways_2_eliminate_all_balls(ball_arrangement):
    """
    Balph is learning to play a game called Buma. In this game, he is given
    a row of colored balls. He has to choose the color of one new ball as
    well as the place to insert it (between two balls, or to the left
    of all the balls, or to the right of all the balls).

    When the ball is inserted the following happens repeatedly: if some
    segment of balls of the same color became longer as a result of a
    previous action, and the length of this segment becomes at least 3,
    then all the balls of this segment are eliminated.

    Consider, for example, a row of balls 'AAABBBWWBB'. Suppose Balph
    chooses a ball of color 'W' and the places it after the
    sixth ball, i. e. to the left of the two 'W's. After Balph inserts
    this ball, the balls of color 'W' are eliminated, since this segment
    was made longer and now has length 3. The row then becomes 'AAABBBBB'.
    The balls of color 'B' are now eliminated, because the segment of balls
    of color 'B' became longer, and have length 5 now. Thus, the row becomes
    'AAA'. However, balls of color 'A' remain, because they have not become
    elongated (i.e. the number of consecutive A's did not change).

    Help Balph count the number of possible ways to choose a color of a
    new ball, and a place to insert it such that the insertion leads to the
    elimination of all balls.

    Input :
    colored_balls_arrangement : <str>
    Contains a non-empty string of uppercase English letters of length at
    most 3*10^5. Each letter represents a ball with the corresponding color.

    Output :
    Output the number of ways to choose a color and a position of a new ball
    in order to eliminate all the balls.
    """
    # Condition 1:
    # In order for any segment of colored balls to be eliminated, a ball of
    # the same color must be placed next to a segment that contains at least
    # two balls of that color. Ball can be inserted anywhere next to that
    # segment.

    # Create a dictionary from 'ball_arrangement'
    ball_segments_map, n_unique_colors = build_ball_dictionary(ball_arrangement)

    # Since the keys of 'ball_dict' refer to starting positions of a distinct
    # ball segment, we can use a list of sorted keys to look through the
    # collection of balls in an ordered manner.
    sorted_ball_segments_by_pos = sorted(ball_segments_map.keys())

    # There are several situations where it is quick and easy to determine
    # that a total elimination of the original row of balls is not possible.
    # This is the case when:
    #   1) There are an even number of distinct ball segments in the original
    #      row of balls. Can be determined by the number of key entries in the
    #      ball segments map/dictionary
    #   2) The total number of balls is fewer than 1 less than three times
    #      the number of uniquely colored ball colors
    #   3) The ball segments at each end of the original row of balls do not
    #      share the same color
    #   4) The ball segments at each end share the same color, but their sum
    #      does not exceed 2

    # Condition 1 for no solution
    if len(sorted_ball_segments_by_pos) % 2 == 0:
        print(0)
        return 0

    # Condition 2 for no solution
    if len(ball_arrangement) < 3 * n_unique_colors - 1:
        print(0)
        return 0

    first_ball_segment_pos = sorted_ball_segments_by_pos[0]
    last_ball_segment_pos = sorted_ball_segments_by_pos[-1]
    first_ball_segment_color = ball_segments_map[first_ball_segment_pos][0]
    last_ball_segment_color = ball_segments_map[last_ball_segment_pos][0]
    # Condition 3 for no solution
    if first_ball_segment_color != last_ball_segment_color:
        print(0)
        return 0

    first_ball_segment_length = ball_segments_map[first_ball_segment_pos][1]
    last_ball_segment_length = ball_segments_map[last_ball_segment_pos][1]
    # Condition 4 for no solution
    if first_ball_segment_length + last_ball_segment_length < 3:
        print(0)
        return 0

    # The key to determining if all balls can be eliminated is by starting from
    # the ball segment that has an equal number of ball segments on either
    # side of it. If there is no complete collapse of balls by inserting a ball
    # into the middle segment, then no solution exists.
    # Find middle index of the sorted key list
    middle_ball_segment_index = len(sorted_ball_segments_by_pos)//2

    # Get the starting position of the current ball segment<key> from the
    # list of sorted ball segment positions<list of keys> using the
    # current ball segment index<int>
    middle_ball_segment_pos = \
        sorted_ball_segments_by_pos[middle_ball_segment_index]

    # Determine if the length of the ball segment (i.e. the 2nd element of
    # the list) associated with the middle ball segment is greater than
    # or equal to 2.
    min_initial_length = 2
    if ball_segments_map[middle_ball_segment_pos][1] >= min_initial_length:
        # If length requirement is satisfied, determine whether the ball
        # segments equidistant from the the middle ball segment share the
        # same color
        count_left_segments = 1
        count_right_segments = 1
        # Continue process outwards until either:
        # 1) one end of the ball segment dictionary has been reached or
        # 2) surrounding ball segments do not share the same ball color or
        # 3) the sum of the outer two surrounding ball segments is not of
        #    sufficient length.
        # Ensure that the bounds of the sorted key list are not exceeded
        while middle_ball_segment_index - count_left_segments >= 0:
            left_segment_index = middle_ball_segment_index - \
                                 count_left_segments
            right_segment_index = middle_ball_segment_index + \
                                  count_right_segments
            left_ball_segment_pos = \
                sorted_ball_segments_by_pos[left_segment_index]

            right_ball_segment_pos =\
                sorted_ball_segments_by_pos[right_segment_index]

            # Check if surrounding ball segments share the same color
            if ball_segments_map[left_ball_segment_pos][0] == \
                    ball_segments_map[right_ball_segment_pos][0]:
                # If the two ball segments equidistant from the middle
                # ball segment are of the same color, check if the sum of
                # the lengths of those two ball segments is greater than 3.
                left_segment_length = ball_segments_map[
                                        left_ball_segment_pos][1]
                right_segment_length = ball_segments_map[
                                        right_ball_segment_pos][1]

                if left_segment_length + right_segment_length >= 3:
                    # If ball segments equidistant from middle ball segment
                    # satisfy all constraints, continue search on the next two
                    # ball segments outwards from the middle.
                    count_left_segments += 1
                    count_right_segments += 1

                # If the ball segments equidistant from the middle ball
                # segment share the same color but, when joined, do not
                # become elongated enough to exceed a length of three,
                # end search, print zero, and return no solution.
                else:
                    print(0)
                    return 0

            # If ball segments equidistant from middle ball segment do not
            # share the same color, end search, print zero, and return no
            # solution
            else:
                print(0)
                return 0

        # if end of while loop is reached, then all balls have been
        # successfully eliminated. Number of solutions is just the length of
        # the middle ball segment + 1
        num_solutions = ball_segments_map[middle_ball_segment_pos][1]+1
        # if num_solutions == 3005:
        print(num_solutions)

    # if middle ball segment does not have at least two balls of the same
    # color, then end search, print 0, and return no solution
    else:
        print(0)
        return 0


if __name__ == "__main__":
    
    new_ball_arrangement = input()
    compute_ways_2_eliminate_all_balls(new_ball_arrangement)

    # Examples
    # inputCopy
    # BBWWBB
    # outputCopy
    # 3
    # inputCopy
    # BWWB
    # outputCopy
    # 0
    # inputCopy
    # BBWBB
    # outputCopy
    # 0
    # inputCopy
    # OOOWWW
    # outputCopy
    # 0
    # inputCopy
    # WWWOOOOOOWWW
    # outputCopy
    # 7
