from fractions import gcd
from functools import reduce
n = int(input())
li = list(map(int,input().split()))
print(reduce(gcd,li))