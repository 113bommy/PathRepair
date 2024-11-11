from fractions import gcd
from functools import reduce
n = int(input())
print(reduce(gcd,map(int,input().split())))