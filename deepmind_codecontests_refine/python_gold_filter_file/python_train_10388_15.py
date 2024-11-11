#!/usr/bin/env python3
#F

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

n = I()
a = LI()
edges = [[] for _ in range(n)]
for _ in range(n-1):
    u, v = LI()
    edges[u-1].append(v-1)
    edges[v-1].append(u-1)

dp = [inf]*n
ans = [None]*n
ans[0] = 1
dp[0] = a[0]
def dfs(s, p, dp, num):
    for u in edges[s]:
        flag = False
        if u == p:
            continue
        r = bl(dp, a[u])
        tmp = dp[r]
        if dp[r] == inf:
            num += 1
            flag = True
        ans[u] = num
        dp[r] = min(dp[r], a[u])
        dfs(u, s, dp, num)
        dp[r] = tmp
        if flag:
            num -= 1
    return
dfs(0, -1, dp, 1)

for i in ans:
    print(i)
        