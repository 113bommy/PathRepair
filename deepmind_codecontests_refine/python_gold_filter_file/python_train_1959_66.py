from fractions import gcd
from functools import reduce
n = int(input())
print(reduce(gcd, list(map(int, input().split()))))