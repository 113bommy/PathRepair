import sys
import math

t = int(sys.stdin.readline().strip())
for i in range(t):
    n, m, a, b = list(map(int,sys.stdin.readline().strip().split(' ')))
    if a*n != m*b:
        print("NO")
    else:
        grid = [[0 for _ in range(m)] for _ in range(n)]
        #print(grid)

        if m%a == 0:
            start = 0
            cnt = 0
            for i in range(n):
                for j in range(start, start+a):
                    grid[i][j] = 1
                cnt += 1
                if cnt == b:
                    cnt = 0
                    start += a
        else:
            start = 0
            for i in range(n):
                for j in range(start, start+a):
                    grid[i][j%m] = 1
                start = (start + a) % m
        print("YES")

        for l in grid:
            print("".join(list(map(str,l))))
