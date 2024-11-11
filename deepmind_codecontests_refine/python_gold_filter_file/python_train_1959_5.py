from functools import reduce
from math import gcd
n = int(input())
A = list(map(int, input().split()))
print(reduce(gcd, A))
