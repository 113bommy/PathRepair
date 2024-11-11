import sys
import itertools
# import numpy as np
import time
import math
import heapq
from collections import defaultdict
sys.setrecursionlimit(10 ** 7)
 
INF = 10 ** 18
MOD = 10 ** 9 + 7
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

# map(int, input().split())

N, K = map(int, input().split())
A = list(sorted(map(int, input().split())))

left = -INF
right = INF
while right - left > 1:
    x = (left + right) // 2
    s = 0 # num of less than or equal to x
    t = 0 # duplication
    for a in A:
        if a > 0:
            l = -1
            r = N
            while r - l > 1:
                m = (l + r) // 2
                if A[m] * a <= x:
                    l = m
                else:
                    r = m
            s += r
        elif a < 0:
            l = -1
            r = N
            while r - l > 1:
                m = (l + r) // 2
                if A[m] * a <= x:
                    r = m
                else:
                    l = m
            s += N - r
        elif a == 0 and x >= 0:
            s += N

        if a * a <= x:
            t += 1
    count = (s - t) // 2
    if count >= K:
        right = x
    else:
        left = x
print(right)
