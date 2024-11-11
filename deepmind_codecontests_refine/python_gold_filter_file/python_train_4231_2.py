# Author: S Mahesh Raju
# Username: maheshraju2020
# Created on: 25/09/2020 16:58:42

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

n = ii1()
arr = iia()
print(n - len(set(arr)) + 1)