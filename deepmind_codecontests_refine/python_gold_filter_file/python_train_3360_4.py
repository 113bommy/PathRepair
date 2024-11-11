# Author: S Mahesh Raju
# Username: maheshraju2020
# Date: 19/09/2020
from sys import stdin, stdout, setrecursionlimit
import heapq
from math import gcd, ceil, sqrt
from collections import Counter, deque
from bisect import bisect_left, bisect_right
from itertools import combinations, permutations
ii1 = lambda: int(stdin.readline().strip())
is1 = lambda: stdin.readline().strip()
iia = lambda: list(map(int, stdin.readline().strip().split()))
isa = lambda: stdin.readline().strip().split()
setrecursionlimit(100000)
mod = 1000000007

tc = ii1()
for _ in range(tc):
    n, x = iia()
    arr = iia()
    tot = 0
    temp = []
    for i in arr:
        tot += x - i
    if set(arr) == set([x]):
        print(0)
    elif tot == 0:
        print(1)
    elif tot != 0 and x in arr:
        print(1)
    else:
        print(2)
    