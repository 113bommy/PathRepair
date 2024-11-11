import sys
import string

from collections import Counter, defaultdict
from math import fsum, sqrt, gcd, ceil, factorial
from itertools import combinations, permutations

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
a = ii()
b = ii()

for i in range(10**7):
    x = n - (i * a)
    if x>=0 and x % b == 0:
        print("YES")
        print(i , x//b)
        exit()
        
print("NO")