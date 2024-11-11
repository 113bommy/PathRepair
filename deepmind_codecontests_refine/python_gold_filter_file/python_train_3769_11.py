import functools
from math import ceil
for x in range(int(input())):
	a=int(input())
	b=list(map(int,input().split()))
	c=functools.reduce(lambda a,b:a+b,b)
	print(ceil(c/a))