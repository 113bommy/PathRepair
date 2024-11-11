import sys
from functools import lru_cache, cmp_to_key
from heapq import merge, heapify, heappop, heappush
from math import *
from collections import defaultdict as dd, deque, Counter as C
from itertools import combinations as comb, permutations as perm
from bisect import bisect_left as bl, bisect_right as br, bisect
from time import perf_counter
from fractions import Fraction
# import numpy as np
sys.setrecursionlimit(int(pow(10,6)))
# sys.stdin = open("input.txt", "r")
# sys.stdout = open("output.txt", "w")
mod = int(pow(10, 9) + 7)
mod2 = 998244353
def data(): return sys.stdin.readline().strip()
def out(*var, end="\n"): sys.stdout.write(' '.join(map(str, var))+end)
def l(): return list(sp())
def sl(): return list(ssp())
def sp(): return map(int, data().split())
def ssp(): return map(str, data().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [l1d(n, val) for j in range(m)]

# @lru_cache(None)

for _ in range(l()[0]):
    n=l()[0]
    A=l()
    e=[]
    o=[]
    # A.sort()
    for i in range(2*n):
        if(A[i]%2):
            o.append(i+1)
        else:
            e.append(i+1)

    for i in range(n-1):

        if(len(o)>=2):
            print(o[0],o[1])
            del(o[0])
            del(o[0])
        else:
            print(e[0],e[1])
            del(e[0])
            del(e[0])        