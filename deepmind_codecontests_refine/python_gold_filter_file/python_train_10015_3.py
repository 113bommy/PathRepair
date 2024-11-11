import sys
import collections
import heapq
import math
 
input = sys.stdin.readline
 
# Library methods start here
def rints(): return map(int, input().strip().split())
def rstr(): return input().strip()
def rint(): return int(input().strip())
def rintas(): return [int(i) for i in input().strip().split()]
    
def gcd(a, b):       
    if (b == 0): return a 
    return gcd(b, a%b) 
 
# Actual Code starts here
n = rint()
for _ in range(n):
    r, c, k = rints()
    d = []
    rices = 0
    grid = [[0 for _ in range(c)] for _ in range(r)]
    for i in range(r):
        grid[i] = [i for i in rstr()]
        for j in range(c):
            if grid[i][j] == 'R': rices+=1 
        if i&1:
            for j in range(c-1, -1, -1):
                d.append([i,j])
        else:
            for j in range(c):
                d.append([i,j])
    # print(grid)
    # print(rices)

    idx = 0
    for i in range(k):
        share = rices//(k-i)
        rices -= share
        if i < 26:
            val = chr(ord('a') + i)
        elif i < 26+26:
            val = chr(ord('A') + (i-26))
        else:
            val = str(i-26-26)

        while share or (i == k-1 and idx < len(d)):
            # print(share, i , k, idx)
            x, y = d[idx]
            idx += 1
            if grid[x][y] == 'R':
                share -= 1
            grid[x][y] = val
    
    for i in range(r):
        print(''.join(grid[i]))
            
            
            
