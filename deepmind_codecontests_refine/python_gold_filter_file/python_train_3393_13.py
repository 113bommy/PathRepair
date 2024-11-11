import sys
from math import *

def minp():
	return sys.stdin.readline().strip()

def mint():
	return int(minp())

def mints():
	return map(int, minp().split())

n = mint()
s = minp()
a = [0]
for i in range(n-1):
	ss = minp()
	ss += ss
	x = ss.find(s)
	if x == -1:
		print(-1)
		exit(0)
	a.append(x)
a.sort()
m = (s+s).find(s,1)
c = sum(a)
r = c
#print(c)
for i in range(n-1):
	c -= (a[i+1] - a[i])*n
	c += m
	#print(c)
	r = min(r, c)
print(r)