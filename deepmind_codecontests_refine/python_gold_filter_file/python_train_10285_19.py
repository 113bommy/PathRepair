from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
import math
import bisect
import random
from itertools import permutations, accumulate, combinations, product
import sys
from pprint import pprint
from copy import deepcopy
import string
from bisect import bisect_left, bisect_right
from math import factorial, ceil, floor
from operator import mul
from functools import reduce
from pprint import pprint


sys.setrecursionlimit(2147483647)
INF = 10 ** 15
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
mod = 1000000007

n = I()
G = [[] for _ in range(n)]
for _ in range(n - 1):
    a, b = LI()
    G[a - 1] += [b - 1]
    G[b - 1] += [a - 1]

memo = [0] * n
par = [-1] * n

def child_cnt(x):
    cnt = 1
    for y in G[x]:
        if y != par[x]:
            par[y] = x
            cnt += child_cnt(y)
    memo[x] = cnt
    return cnt

child_cnt(0)
two_mod = [1] * (n + 1)
for i in range(1, n + 1):
    two_mod[i] = two_mod[i - 1] * 2 % mod

ans = [0] * n
q = deque([0])
while q:
    u = q.pop()
    ret = two_mod[n - 1] - 1
    for v in G[u]:
        if par[u] != v:
            ret = (ret - (two_mod[memo[v]] - 1)) % mod
            q += [v]
    ret = ret - (two_mod[n - memo[u]] - 1)
    ans[u] = ret

print(sum(ans) % mod * pow(two_mod[n], mod - 2, mod) % mod)



