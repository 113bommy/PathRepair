#!/usr/bin/env python3

import sys
import math
from bisect import bisect_right as br
from bisect import bisect_left as bl
sys.setrecursionlimit(2147483647)
from heapq import heappush, heappop,heappushpop
from collections import defaultdict
from itertools import accumulate
from collections import Counter
from collections import deque
from operator import itemgetter
from itertools import permutations
mod = 10**9 + 7
inf = float('inf')
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))

def f(x):
    cnt = 0
    if x < 0:
        j = p-1
        for i in range(m)[::-1]:
            while j >= 0 and plus[j]*minus[i] <= x:
                j -= 1
            cnt += p - j - 1
    else:
        j = 0
        for i in range(m)[::-1]:
            while j < m and minus[j]*minus[i] > x:
                j += 1
            cnt += max(0,i-j)
        j = p-1
        for i in range(p):
            while j >= 0 and plus[j]*plus[i] > x:
                j -= 1
            cnt += max(0,j-i)
        cnt += zero*(zero-1)//2 + m*p + zero*(m+p)
    
    return cnt >= k

n,k = LI()
a = LI()
a.sort()
minus = [x for x in a if x < 0]
plus = [x for x in a if x > 0]
m,p = len(minus),len(plus)
zero = bl(a,1) - br(a,-1)
ok,ng = 10**18,-10**18-1

while ok - ng > 1:
    mid = (ok+ng)//2
    if f(mid):
        ok = mid
    else:
        ng = mid
print(ok)
