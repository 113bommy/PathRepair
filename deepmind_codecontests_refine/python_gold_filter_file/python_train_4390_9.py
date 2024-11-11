import sys,os,io
import math,bisect,operator
inf,mod = float('inf'),10**9+7
# sys.setrecursionlimit(10 ** 6)
from itertools import groupby,accumulate
from heapq import heapify,heappop,heappush
from collections import deque,Counter,defaultdict
input = iter(sys.stdin.buffer.read().decode().splitlines()).__next__
Neo = lambda : list(map(int,input().split()))
test, = Neo()
for _ in range(test):
    n, = Neo()
    A = Neo()
    lcm = min(A)*max(A)
    s,d = set(),2
    while d < min(10**6+1,lcm):
        if lcm%d == 0:
            s.add(d)
            s.add(lcm//d)
        d += 1
    # print(s)    
    if s == set(A):
        print(lcm)
    else:    
        print(-1)
