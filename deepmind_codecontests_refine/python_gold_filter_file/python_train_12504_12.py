import sys
from math import *

def minp():
	return sys.stdin.readline().strip()

n, k = map(int, minp().split())
a = list(map(int, minp().split()))
a.sort(reverse=True)
i = 0
px = a[0]
s = k+1
r = 0
pc = 0
c = 0
z = []
while i < n:
	x = a[i]
	while i < n and a[i] == x:
		c += 1
		i += 1
	while px != x:
		z.append(pc)
		px -= 1
	pc = c
while px != -1:
	z.append(pc)
	px -= 1
#print(z)
if len(z) != 0:
	ze = z[-1]
	while len(z) != 0 and z[-1] == ze:
		z.pop()
#print(z)
for i in z:
	px -= 1
	if s + i > k:
		s = i
		r += 1
	else:
		s += i
print(r)