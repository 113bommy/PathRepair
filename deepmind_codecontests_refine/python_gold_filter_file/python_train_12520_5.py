import sys

# import math
from collections import deque

# import heapq

# from math import inf
# from math import gcd

# print(help(deque))
# 26
pprint = lambda s: print(' '.join(map(lambda x: str(x), s)))
input = lambda: sys.stdin.readline().strip()
ipnut = input
mod = 1000000007
for _ in range(int(input())):
    # z1, o1, t1 = map(int, input().split())
    n = int(input())
    g = [[] for i in range(n)]
    for i in range(n - 1):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        g[a].append(b)
        g[b].append(a)
    # a = list(map(int, input().split()))
    k = int(input())
    lol = list(sorted(map(int, input().split())))
    if k < n - 1:
        lol = [1] * (n - 1-k) + lol
    else:
        for i in range(k - n + 1):
            lol[-2] = (lol[-1] * lol[-2]) % mod
            del lol[-1]
    # print(lol)
    lvl = [-1 for i in range(n)]
    lvl[0] = 0
    bfs = deque()
    bfs.append(0)
    while bfs:
        v = bfs.popleft()
        for u in g[v]:
            if lvl[u] == -1:
                lvl[u] = lvl[v] + 1
                bfs.append(u)
    ver = [i for i in range(n)]
    ver.sort(key=lambda x: -lvl[x])
    # print(ver)
    under = [-1] * n
    ans = []
    for v in ver[:-1]:
        under[v] = 1
        for u in g[v]:
            if under[u] != -1:
                under[v] += under[u]
        ans.append((under[v] * (n - under[v])))
    # print(under)
    ans.sort()
    ansv = 0
    for i in range(n - 1):
        ansv = (ansv + (ans[-1 - i] * lol[-1 - i]) % mod) % mod
    print(ansv)

