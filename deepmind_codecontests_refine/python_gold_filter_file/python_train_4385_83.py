#import sys

#sys.stdin = open('input.txt')
#sys.stdout = open('output.txt', 'w')


def solve():
    time_elevator = 0
    time_stairs = 0
    x, y, z, t1, t2, t3 = map(int, input().split())

    time_stairs = abs(x-y) * t1

    time_elevator = (abs(x-z) * t2) + (abs(x-y) * t2) + 3 * t3

    if time_elevator <= time_stairs:
        return "YES"
    else:
        return "NO"


print(solve())
