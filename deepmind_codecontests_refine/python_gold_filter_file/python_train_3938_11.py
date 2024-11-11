from sys import stdin
import sys
import math
from functools import reduce
import functools
import itertools
from collections import deque,Counter,defaultdict
from operator import mul
import copy
# ! /usr/bin/env python
# -*- coding: utf-8 -*-
import heapq
sys.setrecursionlimit(10**6)
INF =  float("inf")
import bisect

s = input()
n = len(s)

if s[n-1] == "1" or s[0] == "0":
    print(-1)
    sys.exit()

for i in range((n-1) // 2):
    if s[i] != s[n-2-i]:
        print(-1)
        sys.exit()

j = 0
for i in range(1,n):
    if s[i] == "1":
        for k in range(j,i):
            print(k+1,i+1)
        j = i

for k in range(j+1,n):
    print(j+1,k+1)



