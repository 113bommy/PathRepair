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


h, w, k = LI()
A = SRL(h)
q = deque()
for a in range(h):
    if 'S' in A[a]:
        sy = a; sx = A[a].index('S')
        q += [(sy, sx)]

A[sy][sx] = 0
min_dist = INF
while q:
    y, x = q.popleft()
    min_dist = min(min_dist, x, y, h - 1 - y, w - 1 - x)
    for i, j in ((1, 0), (-1, 0), (0, 1), (0, -1)):
        nx, ny = x + i, y + j
        if 0 <= nx < w and 0 <= ny < h and A[ny][nx] == '.':
            A[ny][nx] = A[y][x] + 1
            if A[ny][nx] > k:
                continue
            q += [(ny, nx)]

print(1-(-min_dist // k))







