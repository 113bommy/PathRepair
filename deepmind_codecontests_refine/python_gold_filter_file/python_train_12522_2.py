from sys import stdin, exit, setrecursionlimit
from heapq import *
from collections import deque
from math import *

input = stdin.readline
lmi = lambda: list(map(int, input().split()))
mi = lambda: map(int, input().split())
si = lambda: input().strip('\n')
ssi = lambda: input().strip('\n').split()
mod = 10 ** 9 + 7

n, m = mi()
a = si()
b = si()
dp = [[0 for i in range(m+2)] for j in range(n+2)]
ans = 0
for i in range(n):
    for j in range(m):
        if a[i] == b[j]:
            dp[i][j] = dp[i-1][j-1]+2
        else:
            dp[i][j] = max(1, dp[i-1][j], dp[i][j-1]) - 1
        ans = max(dp[i][j], ans)
print(ans)