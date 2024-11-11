import sys
import string

from collections import Counter, defaultdict
from math import fsum, sqrt, gcd, ceil, factorial
from operator import add

inf = float("inf")
# input = sys.stdin.readline
flush = lambda: sys.stdout.flush
comb = lambda x, y: (factorial(x) // factorial(y)) // factorial(x - y)


# inputs
# ip = lambda : input().rstrip()
ip = lambda: input()
ii = lambda: int(input())
r = lambda: map(int, input().split())
rr = lambda: list(r())

n = ii()
c = 0
i = 1

while i ** 2 < n:
    if n % i == 0:
        c += 2
    i += 1

print(c + int(int(sqrt(n)) ** 2 == n))