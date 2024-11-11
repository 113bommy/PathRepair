import math
from functools import reduce
N, K = map(int, input().split())
A = list(map(int, input().split()))

def gcd_list(numbers):
  return reduce(math.gcd, numbers)

gcd = gcd_list(A)
if (K%gcd==0) and (K<=max(A)):
  print('POSSIBLE')
else:
  print('IMPOSSIBLE')