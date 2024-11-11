import sys
import math,bisect,operator
inf,mod = float('inf'),10**9+7
sys.setrecursionlimit(10 ** 6)
from itertools import groupby,accumulate
from heapq import heapify,heappop,heappush
from collections import deque,Counter,defaultdict
I = lambda : int(sys.stdin.readline())
neo = lambda : map(int, sys.stdin.readline().split())
Neo = lambda : list(map(int, sys.stdin.readline().split()))
for _ in range(I()):
    n,k = neo()
    H = Neo()
    maxi = [0]*(n-1)
    mini = [0]*(n-1)
    maxi[0] = H[0]+k
    mini[0] = H[0]+k
    f = 1
    for i in range(1,n-1):
        curmax = H[i]+k+k-1
        curmn = H[i]+k
        prevmx = maxi[i-1]
        prevmn = mini[i-1]-k
        if curmax <= prevmn:
            f = 0
            break
        if H[i] >= prevmx:
            f = 0
            break
        maxi[i] = min(maxi[i-1]+k-1,curmax)
        mini[i] = max(curmn,prevmn+1)
    if H[-1]+k <= mini[-1]-k or H[-1] >= maxi[-1]:
        f = 0
    print('Yes') if f else print('No')   
       