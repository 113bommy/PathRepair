# -*- coding: utf-8 -*-

import sys
from collections import Counter

def input(): return sys.stdin.readline().strip()
def list2d(a, b, c): return [[c] * b for i in range(a)]
def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
def list4d(a, b, c, d, e): return [[[[e] * d for j in range(c)] for j in range(b)] for i in range(a)]
def ceil(x, y=1): return int(-(-x // y))
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(N=None): return list(MAP()) if N is None else [INT() for i in range(N)]
def Yes(): print('Yes')
def No(): print('No')
def YES(): print('YES')
def NO(): print('NO')
sys.setrecursionlimit(10 ** 9)
INF = 10 ** 18
MOD = 10 ** 9 + 7

N = INT()
A = LIST()

C = sorted(Counter(A).items())
M = len(C)

if C[0][1] > 2:
    print('Impossible')
    exit()

is2src = C[0][1] == 2
src = C[0][0]
depth = src - is2src + 1

if not is2src and C[1][1] < 2:
    print('Impossible')
    exit()

if len(C) != depth:
    print('Impossible')
    exit()

for i, (k, v) in enumerate(C[1:], 1):
    prevk, prevv = C[i-1]
    if k != prevk + 1:
        print('Impossible')
        exit()
    if 2 > v:
        print('Impossible')
        exit()
print('Possible')
