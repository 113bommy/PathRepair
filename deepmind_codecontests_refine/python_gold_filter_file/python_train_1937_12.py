import sys
from math import *

def minp():
	return sys.stdin.readline().strip()

def mint():
	return int(minp())

def mints():
	return map(int, minp().split())

def fact(x):
	r = 1
	for i in range(1, x+1):
		r *= i
	return r

n = mint()
a = list(mints())
a.sort()
i = 0
z = []
while i < n:
	j = i
	while j < n and a[j] == a[i]:
		j += 1
	z.append(j-i)
	if len(z) > 3:
		break
	i = j
if z[0] >= 3:
	print(z[0]*(z[0]-1)*(z[0]-2)//6)
elif z[0] == 2:
	print(z[1])
elif z[0] == 1 and z[1] >= 2:
	print(z[1]*(z[1]-1)//2)
else:
	print(z[2])
