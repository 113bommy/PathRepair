n, k = map(int, input().split())
a = list(map(int, input().split()))

from functools import reduce
from fractions import gcd

g = reduce(gcd, a)

print('POSSIBLE' if (k % g == 0) and (k <= max(a)) else 'IMPOSSIBLE')
