import sys
from functools import lru_cache, cmp_to_key
from heapq import merge, heapify, heappop, heappush
# from math import *
from collections import defaultdict as dd, deque, Counter as C
from itertools import combinations as comb, permutations as perm
from bisect import bisect_left as bl, bisect_right as br, bisect
from time import perf_counter
from fractions import Fraction
import copy
import time
# import numpy as np
starttime = time.time()
# import numpy as np
mod = int(pow(10, 9) + 7)
mod2 = 998244353
def data(): return sys.stdin.readline().strip()
def out(*var, end="\n"): sys.stdout.write(' '.join(map(str, var))+end)
def L(): return list(sp())
def sl(): return list(ssp())
def sp(): return map(int, data().split())
def ssp(): return map(str, data().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [l1d(n, val) for j in range(m)]

try:
    sys.setrecursionlimit(int(pow(10,6)))
    sys.stdin = open("input.txt", "r")
    # sys.stdout = open("../output.txt", "w")
except:
    pass

n,m=L()
A=[L() for i in range(n)]
r=[i for i in range(n)]
c=[i for i in range(m)]
r=set(r)
c=set(c)
p1=0
for i in range(n):
    for j in range(m):
        if A[i][j]:
            p1=1
        else:
            if i in r:
                r.discard(i)
            if j in c:
                c.discard(j)
for i in range(n):
    for j in range(m):
        if A[i][j]==1 and (i not in r and j not in c):
            print("NO")
            exit()
if (len(r)==0 or len(c)==0) and p1==1:
    print("NO")
elif (len(r)==0 or len(c)==0) and p1==0:
    print("YES")
    for i in range(n):
        print(*A[i])
else:
    print("YES")
    for i in range(n):
        for j in range(m):
            if i in r and j in c:
                A[i][j]=1
            else:
                A[i][j]=0
        print(*A[i])



endtime = time.time()
# print(f"Runtime of the program is {endtime - starttime}")