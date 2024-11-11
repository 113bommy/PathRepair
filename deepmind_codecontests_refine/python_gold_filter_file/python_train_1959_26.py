from functools import reduce
from fractions import gcd

n = input()
a = list(map(int, input().split()))

print(reduce(gcd, a))