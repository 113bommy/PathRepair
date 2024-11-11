from functools import reduce
from fractions import gcd
N, X = map(int, input().split())
print(reduce(gcd, list(map(lambda x: abs(int(x)-X), input().split()))))