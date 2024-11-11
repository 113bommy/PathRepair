from functools import reduce
from fractions import gcd
N,X = map(int,input().split())
x = [abs(X-int(a)) for a in input().split()]
print(reduce(gcd,x))