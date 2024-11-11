from fractions import gcd
from functools import reduce

N = int(input())
an = list(map(int,input().split()))

print(reduce(gcd, an))