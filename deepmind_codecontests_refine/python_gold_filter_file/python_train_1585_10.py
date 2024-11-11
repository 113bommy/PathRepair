from bisect import bisect_left, bisect_right
from typing import List
import collections
import bisect
import itertools
import functools
from fractions import gcd
import heapq
from math import ceil, sqrt, floor

import sys
sys.setrecursionlimit(50000)

import collections


T = int(input())
for _ in range(T):
    n = int(input())
    s = list(input())
    v = int(''.join(s))
    result = -1
    while s:
        for i in range(len(s) - 1, -1, -1):
            if int(s[i]) % 2 != 0:
                break
            del s[i]
        if s and sum(int(c) for c  in s) % 2 == 0:
            result = ''.join(s)
            break
        if s:
            del s[-1]
    print(result)
