# -*- coding: utf-8 -*-

import math
import collections
import bisect
import heapq
import time
import itertools
import sys

"""
created by shhuan at 2019/2/13 20:26

"""

N = int(input())

P = [[]]
for i in range(N):
    a, b = map(int, input().split())
    P.append([a, b])

nb = P[1]
ans = [1] + P[1]
if ans[2] not in P[ans[1]]:
    ans = [1] + [P[1][1], P[1][0]]

i = 1
while True:
    nb = [b for b in P[ans[i]] if b != ans[i+1]][0]
    if nb == ans[0]:
        break
    ans.append(nb)
    i += 1

print(' '.join(map(str, ans)))
