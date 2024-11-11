import sys, math
input = sys.stdin.readline

def getInts():
    return [int(s) for s in input().split()]

def getInt():
    return int(input())

def getStrs():
    return [s for s in input().split()]

def getStr():
    return input().strip()

def listStr():
    return list(input().strip())

import collections as col
import math

def solve():
    N, M = getInts()
    ans = min(N,M)+1
    print(ans)
    start_x, start_y = N, 0
    while start_x >= 0 and start_y <= M:
        print(start_x,start_y)
        start_x -= 1
        start_y += 1
    return


    
#for _ in range(getInt()):
solve()
    

