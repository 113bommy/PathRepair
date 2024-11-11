import sys
from functools import lru_cache, cmp_to_key
from heapq import merge, heapify, heappop, heappush, nlargest, nsmallest, _heapify_max, _heapreplace_max
from math import ceil, floor, gcd, fabs, factorial, fmod, sqrt, inf, log
from collections import defaultdict as dd, deque, Counter as c
from itertools import combinations as comb, permutations as perm
from bisect import bisect_left as bl, bisect_right as br, bisect
from fractions import Fraction
# sys.setrecursionlimit(2*pow(10, 6))
# sys.stdin = open("input.txt", "r")
# sys.stdout = open("output.txt", "w")
mod = pow(10, 9) + 7
mod2 = 998244353
def data(): return sys.stdin.readline().strip()
def out(*var, end="\n"): sys.stdout.write(' '.join(map(str, var))+end)
def l(): return list(sp())
def sl(): return list(ssp())
def sp(): return map(int, data().split())
def ssp(): return map(str, data().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [l1d(n, val) for j in range(m)]


n = int(data())
if n & 1:
    out(*[9, n-9])
else:
    out(*[4, n-4])
