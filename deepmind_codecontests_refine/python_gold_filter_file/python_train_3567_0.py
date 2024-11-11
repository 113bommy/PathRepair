#!/usr/bin/env python3
import io
import os
import sys

input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

def printd(*args, **kwargs):
    #print(*args, **kwargs, file=sys.stderr)
    #print(*args, **kwargs)
    pass

def get_str():
    return input().decode().strip()

def rint():
    return map(int, input().split())

def oint():
    return int(input())
n, r1, r2, r3, d = rint()
a = list(rint())

printd(n, r1, r2, r3, d)
printd(a)

dp = [[10**20, 10**20] for i in range(n)]

dp[0][0] = r1*a[0] + r3
dp[0][1] = min(r1*a[0] + r1, r2)

for i in range(1, n):
    # 0 -> 0
    dp[i][0] = min(dp[i][0], dp[i-1][0] + d + r1*a[i] + r3)
    # 1 -> 0
    dp[i][0] = min(dp[i][0], dp[i-1][1] + 3*d + r1*(a[i]+1) + r3)
    dp[i][0] = min(dp[i][0], dp[i-1][1] + 3*d + r1*(a[i]+3))
    dp[i][0] = min(dp[i][0], dp[i-1][1] + 3*d + 2*r1 + r2)
    if i == n - 1:
        dp[i][0] = min(dp[i][0], dp[i-1][1] + 2*d + r1*(a[i]+1) + r3)

    # 0 -> 1
    dp[i][1] = min(dp[i][1], dp[i-1][0] + d + r1*(a[i]+1))
    dp[i][1] = min(dp[i][1], dp[i-1][0] + d + r2)
    # 1 -> 1
    dp[i][1] = min(dp[i][1], dp[i-1][1] + 3*d + r1*(a[i]+2))
    dp[i][1] = min(dp[i][1], dp[i-1][1] + 3*d + r1 + r2)

printd(dp)
print(dp[n-1][0])