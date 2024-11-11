from fractions import gcd
from functools import reduce
n=int(input())
A=list(map(int,input().split()))
print(reduce(gcd, A))