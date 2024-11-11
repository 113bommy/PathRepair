from math import *
from math import factorial
from collections import *
from operator import itemgetter
ii = lambda: int(input())
iia = lambda: list(map(int,input().split()))
isa = lambda: list(input().split())

n = ii()
x = [100000000000000,100000000000000]
for i in range(1,int(sqrt(n))+1):
	a = i
	if(n%i==0):
		b = n//a
		if(a*b/gcd(a,b)==n and max(a,b)<max(x)):
			x[0] = a
			x[1] = b
print(*x)
