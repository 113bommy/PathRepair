from fractions import gcd
from functools import reduce
input()
print(reduce(gcd, tuple(map(int, input().split()))))