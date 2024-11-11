# Young Timofey has a birthday today! He got kit of n cubes as a birthday present
# from his parents. Every cube has a number ai, which is written on it. Timofey
# put all the cubes in a row and went to unpack other presents.
#
# In this time, Timofey's elder brother, Dima reordered the cubes using the
# following rule. Suppose the cubes are numbered from 1 to n in their order. Dima
# performs several steps, on step i he reverses the segment of cubes from i-th to
# (n - i + 1)-th. He does this while i ≤ n - i + 1.
#
# After performing the operations Dima went away, being very proud of himself.
# When Timofey returned to his cubes, he understood that their order was changed.
# Help Timofey as fast as you can and save the holiday — restore the initial
# order of the cubes using information of their current location.
#
# Input
# The first line contains single integer n (1 ≤ n ≤ 2·105) — the number of cubes.
#
# The second line contains n integers a1, a2, ..., an ( - 109 ≤ ai ≤ 109), where
# ai is the number written on the i-th cube after Dima has changed their order.
#
# Output
# Print n integers, separated by spaces — the numbers written on the cubes in
# their initial order.
#
# It can be shown that the answer is unique.

# Example to understand his thing
# go on as long as i <= n-i+1 or 2i <= n+1 = 7 or i = 3

# 1 2 3 4 5 6

# after step 0, reversing 0-th to (n+1)-th - nah.
# after step 1, reversing 1st to n-th:

# 6 5 4 3 2 1

# after step 2, reversing 2nd to (n-1)-th

# 6 2 3 4 5 1

# after step 3, reversig 3rd to fourth

# 6 2 4 3 5 1

# symmetric opeartions, j-th position gets transposed j times for j <= n/2
# switch to zero indexed: j-th position gets transposed j+1 times!

# odd example: same, but middle element stays fixed!

import sys

debug = True if len(sys.argv) > 1 and sys.argv[1] == '-d' else False 

number_of_cubes = int(input())

cubes = [ int(x) for x in input().split(' ') ]

if debug:
    print('going til {}'.format(number_of_cubes//2 -1))

for index in range( (number_of_cubes)//2 ):
    if index%2 == 0:
        if debug:
            print('switching {index} with {other_index}'\
            .format(index=index, other_index=number_of_cubes-index-1))
        cubes[index], cubes[number_of_cubes-index-1] = \
        cubes[number_of_cubes-index-1],  cubes[index]

print(' '.join(map(str,cubes)))

