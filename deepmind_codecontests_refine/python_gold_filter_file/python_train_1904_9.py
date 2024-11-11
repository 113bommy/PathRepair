import math
import sys,bisect
from heapq import *
from itertools import *
from collections import *
sys.setrecursionlimit(10 ** 6)
I = lambda : int(sys.stdin.readline())
neo = lambda : map(int, sys.stdin.readline().split())
Neo = lambda : list(map(int, sys.stdin.readline().split()))
for _ in range(I()):
    n,m = neo()
    A = Neo()
    if sum(A) == m:
        print('YES')
    else:
        print('NO')     
    