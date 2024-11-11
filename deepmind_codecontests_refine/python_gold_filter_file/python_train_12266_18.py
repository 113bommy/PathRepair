from functools import reduce
from fractions import gcd
N,x=map(int,input().split())
X=[abs(int(i)-x) for i in input().split()]
print(reduce(gcd,X))
