import sys
from math import *

def minp():
	return sys.stdin.readline().strip()

def mint():
	return int(minp())

def mints():
	return map(int, minp().split())

n = mint()
a = [0]*n
dp = [0]*n
for i in range(n):
	a[i] = tuple(mints())
a.sort()
for i in range(n):
	x, p = a[i]
	l = -1
	r = n
	v = x-p
	while r-l > 1:
		c = (l + r)//2
		if a[c][0] >= v:
			r = c
		else:
			l = c
		if l == -1:
			dp[i] = i-l-1
		else:
			dp[i] = i-l-1+dp[l]
#print(dp)
z = 1e9
for i in range(n):
	z = min(z,dp[i]+n-i-1)
print(z)