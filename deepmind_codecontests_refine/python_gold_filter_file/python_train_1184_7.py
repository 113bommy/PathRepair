#!/usr/bin/env python3
from sys import stdin


def solve(tc):
    n, k = map(int, stdin.readline().split())

    if n == 1:
        print(0)
        return

    if n <= k:
        print(1)
        return

    lo, hi = 1, k-1
    while lo < hi:
        mid = lo + (hi-lo+1)//2

        cum = (k-2+mid-1)*(k-mid)//2
        if cum < n-k:
            hi = mid - 1
        else:
            lo = mid

    if lo == 1:
        print(-1)
        return

    print(k-lo+1)


tcs = 1
for tc in range(tcs):
    solve(tc)
