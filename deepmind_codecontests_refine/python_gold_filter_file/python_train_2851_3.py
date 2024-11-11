#!/usr/bin/env python3
# created : 2020. 12. 31. 23:59

import os
from sys import stdin, stdout


def solve(tc):
    n = int(stdin.readline().strip())
    tsum = 0
    wsum = 0
    books = []
    for i in range(n):
        books.append(list(map(int, stdin.readline().split())))
        tsum += books[-1][0]
        wsum += books[-1][1]

    dp = [int(1e9) for i in range(tsum+1)]
    dp[0] = wsum
    for i in range(n):
        p, q = books[i]
        for j in range(tsum, p-1, -1):
            dp[j] = min(dp[j], dp[j-p]-q)

    for i in range(tsum+1):
        if dp[i] <= i:
            print(i)
            return


tcs = 1
# tcs = int(stdin.readline().strip())
tc = 1
while tc <= tcs:
    solve(tc)
    tc += 1
