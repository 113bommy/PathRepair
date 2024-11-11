#                                               |
#   _` |  __ \    _` |   __|   _ \   __ \    _` |   _` |
#  (   |  |   |  (   |  (     (   |  |   |  (   |  (   |
# \__,_| _|  _| \__,_| \___| \___/  _|  _| \__,_| \__,_|

import sys
import math
import operator as op
from functools import reduce
from bisect import *
from collections import deque

## I/O ##
def read_line():
    return sys.stdin.readline()[:-1]
 
def read_int():
    return int(sys.stdin.readline())
    
def read_int_line():
    return [int(v) for v in sys.stdin.readline().split()]

def read_float_line():
    return [float(v) for v in sys.stdin.readline().split()]
## ##

## ncr ##
def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return numer / denom
## ##

## Fenwick Tree ##
N = int(1e6)+10
fenwick = [0]*N

def add(i,x,n):
	while i<n:
		fenwick[i]+=x
		i = i|(i+1)

def fsum(i,n):
	res = 0
	while i>=0:
		res += fenwick[i]
		i = (i&(i+1))-1
	return res

def fsum_range(i,j,n):
	return fsum(j,n)-fsum(i-1,n)
## ##	

## Main ##

mod = int(1e9)+7
mod2 = 998244353

# t = read_int()
t = 1
for i in range(t):
	n, m = read_int_line()
	adj = [-1]*(n+1)
	for i in range(m):
		u,v = read_int_line()
		if adj[u]==-1:
			adj[u] = []
			adj[u].append(v)
		else:
			adj[u].append(v)

		if adj[v]==-1:
			adj[v] = []
			adj[v].append(u)
		else:
			adj[v].append(u)

	color = [-1]*(n+1)
	f = True
	q = deque()
	for i in range(1,n+1):
		if color[i]==-1:
			q.append(i)
			color[i] = 0
			while len(q)!=0:
				s = q.popleft()
				if adj[s] !=-1:
					for i in adj[s]:
						if color[i] == -1:
							color[i] = color[s]^1
							q.append(i)
						else:
							if color[i] == color[s]:
								f = False

	if f:
		s1 = []
		s2 = []
		for i in range(1,n+1):
			if color[i]==1:
				s1.append(i)
			else:
				s2.append(i)
		print(len(s1))
		print(*s1)
		print(len(s2))
		print(*s2)
	else:
		print(-1)
