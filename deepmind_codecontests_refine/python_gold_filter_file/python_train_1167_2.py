# Author Name: Ajay Meena
# Codeforce : https://codeforces.com/profile/majay1638
import sys
import math
import bisect
import heapq
from bisect import bisect_right
from sys import stdin, stdout

# -------------- INPUT FUNCTIONS ------------------


def get_ints_in_variables(): return map(
    int, sys.stdin.readline().strip().split())


def get_int(): return int(sys.stdin.readline())


def get_ints_in_list(): return list(
    map(int, sys.stdin.readline().strip().split()))
def get_list_of_list(n): return [list(
    map(int, sys.stdin.readline().strip().split())) for _ in range(n)]


def get_string(): return sys.stdin.readline().strip()

# -------- SOME CUSTOMIZED FUNCTIONS-----------


def myceil(x, y): return (x + y - 1) // y

# -------------- SOLUTION FUNCTION ------------------


def Solution(grid, n):
    # Write Your Code Here
    package = 0
    grid = sorted(grid)
    path = []
    x = 0
    y = 0
    flag = True
    for cord in grid:
        xi = cord[0]
        yi = cord[1]
        if xi < x or yi < y:
            flag = False
            break
        for _ in range(xi-x):
            path.append("R")
        for _ in range(yi-y):
            path.append("U")
        package += 1
        x, y = xi, yi
    if flag and package == n:
        print("YES")
        print("".join(path))
    else:
        print("NO")


def main():
    # Take input Here and Call solution function
    for _ in range(get_int()):
        n = get_int()
        grid = get_list_of_list(n)
        Solution(grid, n)


# calling main Function
if __name__ == '__main__':
    main()
