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

n, m = LI()
G = [set(range(n)) for _ in range(n)]
for i in range(n):
    G[i].remove(i)

for _ in range(m):
    a, b = LI()
    G[a - 1].remove(b - 1)
    G[b - 1].remove(a - 1)

color = [0] * n
def bipartite_or_not(s):
    color[s] = 1
    dq = deque([s])
    b = 1
    w = 0
    while dq:
        u = dq.popleft()
        for v in G[u]:
            if color[v] and color[u] != color[v]:
                continue
            elif color[v] and color[u] == color[v]:
                print(-1)
                exit()
            color[v] = -color[u]
            if color[v] == 1:
                b += 1
            else:
                w += 1
            dq += [v]
    return b, w

bit = 1 << n
for i in range(n):
    if color[i]:
        continue
    x = bipartite_or_not(i)
    p, q = x
    d = abs(p - q)
    bit = bit << d | bit >> d

for j in range(n):
    if bit >> (n - j) & 1:
        y, z = (n + j) // 2, (n - j) // 2
        print(y * (y - 1) // 2 + z * (z - 1) // 2)
        break
