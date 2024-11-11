### 
#def point_sum(point):
#    return point[0]+point[1]

#def point_diff(point):
#    return point[0]-point[1]

#def point_type(point):
#    return "even" if point_sum(point) % 2 == 0 else "odd"

# print(point_sum((2, 1)))
# print(point_type((2, 1)))

def distance(current_point, next_point):

    r1, c1 = current_point[0], current_point[1]
    r2, c2 = next_point[0], next_point[1]
    # distance = cost
    """
    if r1 - c1 == r2 - c2:
        # same diagonal
        if (r1 - c1) % 2 == 1:
            # always can move anywhere on the same odd diagonal
            return 0
        else:
            # even diagonal
            # every move down means cost +1
            # since it's an illegal move
            return r2 - r1

    elif (r1 - c1) % 2 == 1:
        if (r2 - c2) % 2 == 0:
            return ((r2 - c2) - (r1 - c1))//2
        else:
            r2 -= 1
            # add +1 since we moved from odd to even point (up 1 row)
            return ((r2 - c2) - (r1 - c1))//2 + 1

    else:
        # (r1 - c1) % 2 == 0
        if (r2 - c2) % 2 == 1:        
            r1 += 1
            # we move from even to odd point (down 1 row)
            return ((r2 - c2) - (r1 - c1))//2 + 1
        else:
            # both points even
            # cost = number of rows between points
            return (r2 - r1)
    """

    if (r1 - c1) % 2 == 1:

        if (r2 - c2) % 2 == 1:
            if (r1 - c1) == (r2 - c2):
                # same odd diagonal
                return 0
            else:
                # different odd diagonals
                # cost is the number of rows in between points
                return ((r2 - c2) - (r1 - c1))//2
            
        else:
            # r2 - c2 % 2 == 0
            return ((r2 - c2) - (r1 - c1) + 1)//2

    else:
        # (r1 - c1) % 2 == 0
        if (r2 - c2) % 2 == 1:
            return ((r2 - c2) - (r1 - c1) - 1)//2
        else:
            # (r2 - c2) % 2 == 0:
            if (r1 - c1) == (r2 - c2):
                # same even diagonal
                # the cost is the number of rows between points
                # since every move down is illegal
                return (r2 - r1)

            else:            
                return ((r2 - c2) - (r1 - c1))//2
    
    
def solve(n, lc, coordinates):  
    """
    the new and updated map:
    
    previously i had everything pushed left but the original layout is a pyramid:
    
                (1, 1),
            (2, 1), (2, 2),
        (3, 1), (3, 2), (3, 3),
    (4, 1), (4, 2), (4, 3), (4, 4),


    ...
    (n, 1), (n, 2), ..., (n, n-1), (n, n)

    where "even" points allow only left moves
    and "odd" points allow only right moves

    but now i have found this layout:

                0,
              1, 0,
            2, 1, 0,
          3, 2, 1, 0,
        4, 3, 2, 1, 0
      5, 4, 3, 2, 1, 0,
    6, 5, 4, 3, 2, 1, 0,

    ...

    n-1, n-2, ..., 1, 0

    this layout is formed by replacing all points with the value of r-c
    ie for point (1, 1) i have replaced it with 1-1=0
    for point (4, 2) i replace with 4-2=2
    and so on and so forth

    let's denote the term "odd diagonal" as a diagonal of the layout plan following
    only odd values, ie the diagonal consisting of only 1s is an "odd diagonal"

    then an "even diagonal" is a diagonal following only even values, ie the diagonal
    consisting of just 4s is an "even diagonal"

    an "increasing" diagaonl is a diagonal in which the values increase,
    ie every diagonal that is NOT even or odd is an "increasing" diagonal
    these diagonals go top right to bottom left

    activate a new edge/path = make an "illegal" move
    
    """

    # initialize cost = 0
    cost = 0

    # our current point
    # always start at the top
    current_point = (1, 1)   
    coordinates_index = 0

    # while there's still coordinates to visit
    while coordinates_index < lc:
        next_point = coordinates[coordinates_index]
            
        cost = cost + distance(current_point, next_point)
        
        current_point = next_point

        coordinates_index += 1

    # finally
    return cost

t = int(input())
for tc in range(t):
    n = int(input())
    rs = [int(r) for r in input().split()]
    cs = [int(c) for c in input().split()]
    coordinates = []
    for i in range(n):
        coordinates.append((rs[i], cs[i]))
    # sort by row
    # default sort by first item
    coordinates = sorted(coordinates)
    lc = len(coordinates)
    # print(n, lc, coordinates)
    print(solve(n, lc, coordinates))
    
