# -*- coding: utf-8 -*-

import sys
from itertools import accumulate

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

N, K = MAP()
mod = K * 2
XY = []
MAX = K*4 + 7
acc = list2d(MAX, MAX, 0)
for i in range(N):
    x, y, c = input().split()
    x = int(x)
    y = int(y)
    x %= mod
    y %= mod
    if c == 'B':
        x += K
    for a1 in range(3):
        for a2 in range(3):
            for b in [0, K]:
                if c == 'B':
                    b = -b
                x1 = x + a1 * mod + b
                y1 = y + a2 * mod + b
                x2 = x1 + K
                y2 = y1 + K
                x1 = max(min(x1, MAX-1), 0)
                y1 = max(min(y1, MAX-1), 0)
                x2 = max(min(x2, MAX-1), 0)
                y2 = max(min(y2, MAX-1), 0)
                acc[x1][y1] += 1
                acc[x2][y2] += 1
                acc[x1][y2] -= 1
                acc[x2][y1] -= 1

for i in range(MAX):
    acc[i] = list(accumulate(acc[i]))
for j in range(MAX):
    for i in range(MAX-1):
        acc[i+1][j] += acc[i][j]
mx = 0
for j in range(K*2, K*4):
    for i in range(K*2, K*4):
        mx = max(mx, acc[i][j])
print(mx)
