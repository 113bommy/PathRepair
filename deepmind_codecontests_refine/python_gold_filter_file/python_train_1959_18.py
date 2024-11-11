import math
from functools import reduce

n = int(input())
a = list(map(int, input().split()))

print(reduce(math.gcd, a))