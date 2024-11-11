
import math
import sys
input=sys.stdin.readline
from collections import Counter, defaultdict, deque

def f(a, b, c, d, n, x):
    grid = [["." for co in range(a+c)]for r in range(max(b, d))]
    alphnum = 97
    pos = 0
    if (a+1)%2:#c odd start from top
        for co in range(a):
            if co % 2==0:
                r = 0
                while r < b:
                    grid[r][co] = chr(alphnum)
                    x[pos] -= 1
                    if x[pos] == 0:
                        pos += 1
                        alphnum += 1
                    r += 1
            else:
                r = b-1
                while r > -1:
                    grid[r][co] = chr(alphnum)
                    x[pos] -= 1
                    if x[pos] == 0:
                        pos += 1
                        alphnum += 1
                    r -= 1
        # for r in range(max(b, d)):
        #     print(grid[r])
        for co in range(a, a+c):
            if co%2==0:
                r = 0
                while r < d:
                    #print(r, co)
                    grid[r][co] = chr(alphnum)
                    x[pos] -= 1
                    if x[pos] == 0:
                        pos += 1
                        alphnum += 1
                    r += 1
                #print(r, c)
            else:
                r = d-1
                while r > -1:
                    #print(r, co)
                    grid[r][co] = chr(alphnum)
                    x[pos] -= 1
                    if x[pos] == 0:
                        pos += 1
                        alphnum += 1
                    r -= 1
    else:#c even start from down
        for co in range(a):
            if co % 2==1:
                r = 0
                while r < b:
                    grid[r][co] = chr(alphnum)
                    x[pos] -= 1
                    if x[pos] == 0:
                        pos += 1
                        alphnum += 1
                    r += 1
            else:
                r = b-1
                while r > -1:
                    grid[r][co] = chr(alphnum)
                    x[pos] -= 1
                    if x[pos] == 0:
                        pos += 1
                        alphnum += 1
                    r -= 1
        # for r in range(max(b, d)):
        #     print(grid[r])
        for co in range(a, a+c):
            if co%2==1:
                r = 0
                while r < d:
                    #print(r, co)
                    grid[r][co] = chr(alphnum)
                    x[pos] -= 1
                    if x[pos] == 0:
                        pos += 1
                        alphnum += 1
                    r += 1
                #print(r, c)
            else:
                r = d-1
                while r > -1:
                    #print(r, co)
                    grid[r][co] = chr(alphnum)
                    x[pos] -= 1
                    if x[pos] == 0:
                        pos += 1
                        alphnum += 1
                    r -= 1


    # for r in range(max(b, d)):
    #     print(grid[r])
    return grid

    

    
    


t = 1
result = []
for i in range(t):
    #n = int(input())
    a, b, c, d, n = list(map(int, input().split()))
    x = list(map(int, input().split()))
    result.append(f(a, b, c, d, n, x))
for i in range(t):
    print("YES")
    for j in range(len(result[i])):
        print("".join(result[i][j]))

