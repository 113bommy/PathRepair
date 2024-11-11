from functools import reduce
from math import gcd

n, x = map(int, input().split())
a = [abs(int(A) - x) for A in input().split()]
a.sort()
print(reduce(gcd, a))
