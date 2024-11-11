import sys
import itertools
# import numpy as np
import time
import math
import heapq
from collections import defaultdict
sys.setrecursionlimit(10 ** 7)
 
INF = 10 ** 9 + 7
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

# map(int, input().split())

MOD = 10 ** 9 + 7
def my_pow(base, n, mod):
    if n == 0:
        return 1
    x = base
    y = 1
    while n > 1:
        if n % 2 == 0:
            x *= x
            n //= 2
        else:
            y *= x
            n -= 1
        x %= mod
        y %= mod
    return x * y % mod

N = int(input())

adj = [[] for _ in range(N)]
for i in range(N - 1):
    a, b = map(int, input().split())
    a -= 1    
    b -= 1
    adj[a].append(b)
    adj[b].append(a)

pows = [1] * N
for i in range(1, N):
    pows[i] = (pows[i - 1] * 2) % MOD

ans = 0
def dfs(v, p):
    global ans
    subs = []
    res = 1
    for u in adj[v]:
        if u == p:
            continue
        val = dfs(u, v)
        res += val
        subs.append(val)
    # add sub-tree on the parent side
    if p != -1:
        subs.append(N - res)
    now = pows[N - 1] - 1 # N - 1 means that it chooses freelye other than v
    for sub in subs:
        now -= pows[sub] - 1
    ans += now
    ans %= MOD
    return res

dfs(0, -1)
print(ans * my_pow(2 ** N, MOD - 2, MOD) % MOD)