from fractions import gcd
from functools import reduce
N = int(input())
A = list(map(int,input().split()))
print(reduce(gcd,A))