import sys
import string
from heapq import *
from bisect import *

from collections import Counter, defaultdict
from math import fsum, sqrt, gcd, ceil, factorial
from operator import *
from itertools import accumulate

inf = float("inf")
# input = sys.stdin.readline
flush = lambda: sys.stdout.flush
comb = lambda x, y: (factorial(x) // factorial(y)) // factorial(x - y)
en = lambda x: list(enumerate(x))


# inputs
# ip = lambda : input().rstrip()
ip = lambda: input()
ii = lambda: int(input())
r = lambda: map(int, input().split())
rr = lambda: list(r())


n = ii()
arr = rr()
arr = list(accumulate(arr, add))
for i in range(n):
    if arr[i] >= ((arr[-1] + 1) // 2):
        print(i + 1)
        exit()