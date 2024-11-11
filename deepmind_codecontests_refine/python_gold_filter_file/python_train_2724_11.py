# -*- coding:utf-8 -*-

"""

created by shuangquan.huang at 9/17/19

https://noi.ph/training/weekly/week3.pdf
"""

import collections
import time
import os
import sys
import bisect
import heapq


N1, N2, K1, K2 = map(int, input().split())

memo = {}
MOD = 100000000
def solve(f, h, kf, kh):
    key = (f, h, kf, kh)
    if key in memo:
        return memo[key]
    
    if f + h == 0:
        return 1
    
    ans = 0
    if f > 0 and kf > 0:
        ans += solve(f-1, h, kf-1, K2)
    if h > 0 and kh > 0:
        ans += solve(f, h-1, K1, kh-1)
    ans %= MOD
    
    memo[key] = ans
    
    return ans

print(solve(N1, N2, K1, K2))