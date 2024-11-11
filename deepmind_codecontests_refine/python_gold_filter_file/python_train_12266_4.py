from functools import reduce
from fractions import gcd
n,x = map(int,input().split())
X = list(map(int,input().split()))
X = [abs(a-x) for a in X]
print(reduce(gcd,X))