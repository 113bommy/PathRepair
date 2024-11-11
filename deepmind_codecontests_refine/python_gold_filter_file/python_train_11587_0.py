import sys
import math,bisect,operator
inf,m = float('inf'),10**9+7
sys.setrecursionlimit(10 ** 5)
from itertools import groupby,accumulate
from heapq import heapify,heappop,heappush
from collections import deque,Counter,defaultdict
I = lambda : int(sys.stdin.readline())
neo = lambda : map(int, sys.stdin.readline().split())
Neo = lambda : list(map(int, sys.stdin.readline().split()))
for _ in range(I()):
    n,m = neo()
    A = Neo()
    B = Neo()
    print(n+m-len(set(A+B)))