import sys
from math import *

def minp():
	return sys.stdin.readline().strip()

def mint():
	return int(minp())

def mints():
	return map(int, minp().split())

def getans(n,k):
	r = 0
	while n > 0:
		z = min(k, n)
		r += z
		n -= z
		n = n-(n//10)
	return r

n = mint()
r = n
l = 0
while (r-l > 1):
	c = (r+l)//2
	if getans(n,c)*2 >= n:
		r = c
	else:
		l = c
print(r)