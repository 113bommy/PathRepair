from functools import reduce
from fractions import gcd
n, x = map(int, input().split())
X = [abs(x-int(i)) for i in input().split()]
print(reduce(gcd, X))