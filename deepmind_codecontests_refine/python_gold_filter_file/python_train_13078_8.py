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
created by shhuan at 2017/11/27 01:21

"""


N = int(input())
A = [int(x) for x in input().split()]

ans = float('inf')

total = sum(A or [0])
for i in range(N):
    for j in range(i, N):
        a = sum(A[i: j] or [0])
        b = total - a
        ans = min(ans, abs(a-b))

print(ans)