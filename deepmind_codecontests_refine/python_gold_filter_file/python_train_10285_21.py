from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
import math
import bisect
import random
from itertools import permutations, accumulate, combinations, product
import sys
import string
from bisect import bisect_left, bisect_right
from math import factorial, ceil, floor
from operator import mul
from functools import reduce
from operator import mul


sys.setrecursionlimit(2147483647)
INF = 10 ** 20
def LI(): return list(map(int, sys.stdin.readline().split()))
def I(): return int(sys.stdin.readline())
def LS(): return sys.stdin.buffer.readline().rstrip().decode('utf-8').split()
def S(): return sys.stdin.buffer.readline().rstrip().decode('utf-8')
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
def LSR(n): return [LS() for i in range(n)]
def SRL(n): return [list(S()) for i in range(n)]
def MSRL(n): return [[int(j) for j in list(S())] for i in range(n)]
mod = 1000000007


n = I()
G = [[] for _ in range(n)]
for _ in range(n - 1):
    a, b = LI()
    G[a - 1] += [b - 1]
    G[b - 1] += [a - 1]


par = [-1] * n
cnt = [0] * n


def f(u):
    ret = 1
    for v in G[u]:
        if v == par[u]:
            continue
        par[v] = u
        ret += f(v)
    cnt[u] = ret
    return ret

f(0)
pow2 = [1] * (n + 1)
for i in range(1, n + 1):
    pow2[i] = pow2[i - 1] * 2 % mod

q = deque([0])
ans = 0
while q:
    u = q.pop()
    ret = pow2[n - 1] - 1
    for v in G[u]:
        if v == par[u]:
            continue
        ret -= pow2[cnt[v]] - 1
        q += [v]
    ret -= pow2[n - cnt[u]] - 1
    ans = (ans + ret) % mod

print(ans * pow(pow2[n], mod - 2, mod) % mod)




