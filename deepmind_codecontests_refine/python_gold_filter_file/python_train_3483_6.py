# aadiupadhyay
import os.path
from math import gcd, floor, ceil
from collections import *
import sys
mod = 1000000007
INF = float('inf')
def st(): return list(sys.stdin.readline().strip())
def li(): return list(map(int, sys.stdin.readline().split()))
def mp(): return map(int, sys.stdin.readline().split())
def inp(): return int(sys.stdin.readline())
def pr(n): return sys.stdout.write(str(n)+"\n")
def prl(n): return sys.stdout.write(str(n)+" ")


if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

t, k = mp()
l = []
c = 0
for _ in range(t):
    a, b = mp()
    l.append([a, b])
    c = max(c, b)
dp = [1 for i in range(c+1)]
pre = list(dp)
for i in range(1, k):
    pre[i] = pre[i-1] + 1
    pre[i] %= mod


for i in range(k, c+1):
    dp[i] = dp[i-k] + dp[i-1]
    dp[i] %= mod
    pre[i] = pre[i-1] + dp[i]
    pre[i] %= mod
for i in l:
    a, b = i
    ans = (pre[b] - pre[a-1] + mod) % mod
    pr(ans)
