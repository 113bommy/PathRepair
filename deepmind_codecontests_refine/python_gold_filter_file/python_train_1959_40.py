import math
from functools import reduce
N = int(input())
A = list(map(int, input().split()))

print(reduce(math.gcd, A))