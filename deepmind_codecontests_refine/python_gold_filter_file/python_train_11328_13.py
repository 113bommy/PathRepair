from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
from bisect import bisect_right, bisect_left
import random
from itertools import permutations, accumulate, combinations, product
import sys
import string
from bisect import bisect_left, bisect_right
from math import factorial, ceil, floor, gamma, log
from operator import mul
from functools import reduce
from copy import deepcopy

sys.setrecursionlimit(2147483647)
INF = 10 ** 20
def LI(): return list(map(int, sys.stdin.readline().split()))
def I(): return int(sys.stdin.readline())
def LS(): return sys.stdin.buffer.readline().rstrip().split()
def S(): return sys.stdin.buffer.readline().rstrip().decode('utf-8')
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): pass
def LSR(n): return [LS() for i in range(n)]
def SRL(n): return [list(S()) for i in range(n)]
def MSRL(n): return [[int(j) for j in list(S())] for i in range(n)]
mod = 10 ** 9 + 7

n = I()

fac = [1] * (n + 1)
inv = [1] * (n + 1)
for j in range(1, n + 1):
    fac[j] = fac[j-1] * j % mod


inv[n] = pow(fac[n], mod-2, mod)
for j in range(n-1, -1, -1):
    inv[j] = inv[j+1] * (j+1) % mod


def comb(n, r):
    if r > n or n < 0 or r < 0:
        return 0
    return fac[n] * inv[n - r] * inv[r] % mod

s = input()
dp = [[0] * n for _ in range(n)]
dp[0][0] = 1
for i in range(1, n):
    ret = 0
    if s[i - 1] == "<":
        for j in range(i - 1, -1, -1):
            ret += dp[i - 1][j]
            ret %= mod
            dp[i][j] = ret
    else:
        for j in range(1, i + 1):
            ret += dp[i - 1][j - 1]
            dp[i][j] = ret
        dp[i][i] = ret

print(sum(dp[-1]) % mod)
