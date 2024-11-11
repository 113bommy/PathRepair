from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
import math
import bisect
import random
from itertools import permutations, accumulate, combinations, product
import sys
import string
from bisect import bisect_left, bisect_right
from math import factorial, ceil, floor, gcd
from operator import mul
from functools import reduce
from operator import mul
from pprint import pprint



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



l, r = LI()
L = r.bit_length()
dp = [[[[0] * 2 for _ in range(2)] for _ in range(2)] for _ in range(L+1)]
dp[0][0][0][0] = 1


for i in range(L):
    rd = r >> L - i - 1 & 1
    ld = l >> L - i - 1 & 1
    for l_flg in range(2):
        for r_flg in range(2):
            for c in range(2):
                for ri, li in ((1, 0), (1, 1), (0, 0)):
                    if c == 0 and ri == 1 and li == 0:
                        continue
                    if (l_flg == 0 and li < ld) or (r_flg == 0 and ri > rd):
                        continue
                    dp[i + 1][l_flg or li > ld][r_flg or ri < rd][c or (ri == 1 and li == 1)] += dp[i][l_flg][r_flg][c]
                    dp[i + 1][l_flg or li > ld][r_flg or ri < rd][c or (ri == 1 and li == 1)] %= mod

ret = 0
for a in range(2):
    for b in range(2):
        for d in range(2):
            ret += dp[L][a][b][d]

print(ret % mod)



