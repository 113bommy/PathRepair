
def STR(): return list(input())
def INT(): return int(input())
def MAP(): return map(int, input().split())
def MAP2():return map(float,input().split())
def LIST(): return list(map(int, input().split()))
def STRING(): return input()
from heapq import heappop , heappush
from bisect import *
from collections import deque , Counter
from math import *
from itertools import permutations
dx = [-1 , 1 , 0 , 0  ]
dy = [0 , 0  , 1  , - 1]
#visited = [[False for i in range(m)] for j in range(n)]
#for tt in range(INT()):

for tt in range(INT()):
    x , y , z = MAP()

    if z == 0 and x <= y :
        print(0)

    elif z == 0 and x > y :
        print(1)

    elif x + z <= y :
        print(0)

    else:
        l , r=  0 , z
        while l<= r :
            mid = l + (r - l )//2
            if x + (z - mid) > mid + y :
                l = mid + 1
            else:
                r = mid - 1

        if r >= 0 :
            print(r + 1)
        else:
            print(0)
