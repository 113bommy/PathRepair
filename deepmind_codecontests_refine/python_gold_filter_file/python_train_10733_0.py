import sys
from math import *
from random import *

def minp():
	return sys.stdin.readline().strip()

def mint():
	return int(minp())

def mints():
	return map(int, minp().split())

def solve():
	n = mint()
	e = [[] for i in range(n+1)]
	p = [None]*(n+1)
	my = [False]*(n+1)
	for i in range(n-1):
		a,b = mints()
		e[a].append(b)
		e[b].append(a)
	def dfs(x):
		for i in e[x]:
			if p[i] == None:
				p[i] = x
				dfs(i)
	k1 = mint()
	x = list(mints())
	for i in x:
		my[i] = True
	k2 = mint()
	y = list(mints())
	p[x[0]] = 0
	dfs(x[0])
	print('B',y[0])
	sys.stdout.flush()
	z = mint()
	while my[z] != True:
		z = p[z]
	print('A',z)
	sys.stdout.flush()
	zz = mint()
	if zz in y:
		print('C',z)
	else:
		print('C',-1)
	sys.stdout.flush()

t = mint()
for i in range(t):
	solve()
