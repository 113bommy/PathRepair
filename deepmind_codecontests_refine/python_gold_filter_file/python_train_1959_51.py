from fractions import gcd
from functools import reduce
_=input()
print(reduce(gcd,map(int,input().split())))