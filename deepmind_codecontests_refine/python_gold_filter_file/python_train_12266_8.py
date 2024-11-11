from functools import reduce
from fractions import gcd
N,x = map(int,input().split())
X =[abs(i-x) for i in map(int,input().split())]
print(reduce(gcd,X))