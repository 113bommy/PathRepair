#!/usr/bin/env python3
# created : 2020. 12. 31. 23:59

import os
from sys import stdin, stdout


def solve(tc):
    ingredient = stdin.readline().strip()
    kitchen = list(map(int, stdin.readline().split()))
    cost = list(map(int, stdin.readline().split()))
    money = int(stdin.readline().strip())

    ahamburger = [0, 0, 0]
    for c in ingredient:
        if c == 'B':
            ahamburger[0] += 1
        elif c == 'S':
            ahamburger[1] += 1
        else:
            ahamburger[2] += 1

    lo, hi = 0, int(1e12+101)
    while lo < hi:
        mid = lo + (hi-lo)//2

        needed = 0
        for i in range(3):
            if ahamburger[i]:
                cnt = max(0, ahamburger[i] * mid - kitchen[i])
                needed += cnt * cost[i]
                if needed>money:
                    break

        if needed <= money:
            lo = mid + 1
        else:
            hi = mid

    if lo>0:
        lo -= 1
    print(lo)


tcs = 1
# tcs = int(stdin.readline().strip())
tc = 1
while tc <= tcs:
    solve(tc)
    tc += 1
