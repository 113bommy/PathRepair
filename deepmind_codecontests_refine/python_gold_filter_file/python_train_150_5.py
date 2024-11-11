from functools import reduce
from operator import *
from math import *
from sys import *
setrecursionlimit(10**7)
RI=lambda: list(map(int,input().split()))
RS=lambda: input().rstrip().split()
#################################################
n=RI()[0]
x=RS()[0]
for i in range(n):
	for j in range(1,n):
		if x[i::j][:5]=='*'*5:
			print("YES")
			exit(0)
print("NO")
