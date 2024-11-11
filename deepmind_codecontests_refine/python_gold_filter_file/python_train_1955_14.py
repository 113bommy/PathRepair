import sys
import itertools
# import numpy as np
import time
import math
import heapq
from collections import defaultdict
from collections import Counter
sys.setrecursionlimit(10 ** 7)
 
INF = 10 ** 18
MOD = 10 ** 9 + 7
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

# map(int, input().split())
N = int(input())
MAX = 10 ** 9
d = defaultdict(int)
for i in range(N):
    a = round(float(input()) * MAX)
    two = 0
    while a % 2 == 0:
        two += 1
        a //= 2
    five = 0
    while a % 5 == 0:
        five += 1
        a //= 5
    d[(two, five)] += 1

ans = 0
for p1 in d.keys():
    for p2 in d.keys():
        if (p1[0] + p2[0] >= 18) and (p1[1] + p2[1] >= 18):
            if p1 < p2:
                ans += d[p1] * d[p2]
            elif p1 == p2:
                ans += d[p1] * (d[p1] - 1) // 2
print(ans)