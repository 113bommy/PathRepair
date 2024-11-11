#!/usr/bin/env python3
import collections, itertools, functools, math

def solve():
    n, a, b = map(int, input().split())
    grid = [[0]*b for _ in range(a)]

    dem = 1
    rep = 2
    for i in range(a):
        for j in range(b):
            if (i+j)%2 == 0:
                if dem <= n:
                    grid[i][j] = dem
                    dem += 2
            else:
                if rep <= n:
                    grid[i][j] = rep
                    rep += 2

    if dem <= n or rep <= n:
        print(-1)
    else:
        for row in grid:
            print(*row)


if __name__ == '__main__':
    solve()

