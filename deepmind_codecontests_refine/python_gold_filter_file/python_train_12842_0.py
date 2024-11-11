import sys
from math import *

def minp():
	return sys.stdin.readline().strip()

def mint():
	return int(minp())

def mints():
	return map(int, minp().split())

a,b,k = mints()

p = [True]*(b+1)
for i in range(2, b+1):
	if p[i]:
		for j in range(i*i, b+1, i):
			p[j] = False

p[1] = False
#d = []
#for i in range(a, b+1)
#	if p[i]:
#		d.append(i)
c = 0
i = a
q = [0]*(b+1)
ql = 1
qr = 1
q[0] = a-1
while c < k and i <= b:
	if p[i]:
		c += 1
		q[qr] = i
		qr += 1
	i += 1
if c != k:
	print(-1)
	exit(0)
#print(q[qr-1],a)
r = q[qr-1]-a
while i <= b:
	#print(r, q[qr-1],q[ql-1]+1)
	r = max(r, q[qr-1]-(q[ql-1]+1))
	ql += 1
	c -= 1
	while i <= b:
		if p[i]:
			q[qr] = i
			qr += 1
			c += 1
			i += 1
			break
		i += 1
if c == k:
	#print(r, b, q[ql-1]+1)
	r = max(r, b-q[ql-1]-1)
else:
	#print(r, b, q[ql-1])
	r = max(r, b-q[ql-1])
print(r+1)