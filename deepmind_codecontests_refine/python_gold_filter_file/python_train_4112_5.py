# -*- coding: utf-8 -*-

import math
import collections
import bisect
import heapq
import time
import random
import itertools
import sys

"""
created by shhuan at 2017/11/24 21:40

"""

N = int(input())

# 1,..., 9   => 9*1
# 10, ..., 99 = > 90*2
# 100, ... , 999 => 900*3
# 10000, ..., 9999 => 9000*4

def f(n):
    if n < 10:
        return n
    i = 0
    while 10**i <= n:
        i += 1

    i -= 1

    ans = 0
    for j in range(1, i+1):
        ans += 9 * (10**(j-1)) * j

    ans += (n-10**i+1) * (i+1)
    return ans

    #return ans + (i+1)*f(n-10**i+1)

print(f(N))



