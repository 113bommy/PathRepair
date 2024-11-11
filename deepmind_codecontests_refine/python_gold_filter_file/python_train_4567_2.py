from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
import math
import bisect
import random
from itertools import permutations, accumulate, combinations, product
import sys
import string
from bisect import bisect_left, bisect_right
from math import factorial, ceil, floor, cos, radians, pi, sin
from operator import mul
from functools import reduce
from operator import mul

mod = 10 ** 9 + 7
sys.setrecursionlimit(2147483647)
INF = 10 ** 13
def LI(): return list(map(int, sys.stdin.buffer.readline().split()))
def I(): return int(sys.stdin.buffer.readline())
def LS(): return sys.stdin.buffer.readline().rstrip().decode('utf-8').split()
def S(): return sys.stdin.buffer.readline().rstrip().decode('utf-8')
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
def LSR(n): return [LS() for i in range(n)]
def SRL(n): return [list(S()) for i in range(n)]
def MSRL(n): return [[int(j) for j in list(S())] for i in range(n)]


n = I()
G = [[] for _ in range(n)]
for _ in range(n - 1):
    a, b = LI()
    G[a - 1] += [b - 1]
    G[b - 1] += [a - 1]

cond = [(-INF, INF) for _ in range(n)]
k = I()
for _ in range(k):
    v, p = LI()
    cond[v - 1] = (p, p)

ans = [0] * n
visited = [0] * n
def f(u):
    visited[u] = 1
    max_ret = cond[u][1]
    min_ret = cond[u][0]
    u_flg = max_ret % 2 if max_ret == min_ret else -1
    for v in G[u]:
        if visited[v]:
            continue
        x, y, flg = f(v)
        if flg != -1 and u_flg == flg:
            print("No")
            exit()
        max_ret = min(max_ret, y + 1)
        min_ret = max(min_ret, x - 1)
    if min_ret > max_ret:
        print("No")
        exit()
    cond[u] = (min_ret, max_ret)
    return min_ret, max_ret, u_flg

f(0)
print("Yes")
visited = [0] * n
ans = [-1] * n
ans[0] = cond[0][0]
def f2(u):
    visited[u] = 1
    for v in G[u]:
        if visited[v]:
            continue
        ans[v] = ans[u] + 1 if cond[v][0] <= ans[u] + 1 <= cond[v][1] else ans[u] - 1
        f2(v)

f2(0)
print(*ans, sep="\n")