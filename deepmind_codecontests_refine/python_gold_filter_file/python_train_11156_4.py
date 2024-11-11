from __future__ import print_function # for PyPy2
from collections import Counter, OrderedDict
from itertools import permutations as perm
from fractions import Fraction
from collections import deque
from sys import stdin
from bisect import *
from heapq import *
from math import *

g   = lambda : stdin.readline().strip()
gl  = lambda : g().split()
gil = lambda : [int(var) for var in gl()]
gfl = lambda : [float(var) for var in gl()]
gcl = lambda : list(g())
gbs = lambda : [int(var) for var in g()]
mod = int(1e9)+7
inf = float("inf")   

n, = gil()

if n < 3:
	print(-1)
	exit()

cnt = n

N = int(2e3)
p = [1]*(N+1)
p[0] = p[1] = 0
N_ = ceil(sqrt(N))+1
for i in range(N_):
	if p[i] and i <= N_:
		for j in range(i+i, N+1, i):
			p[j] = 0

ans = []
i = 1

while p[cnt] == 0:
	ans.append(str(i)+' '+str(i+(n//2)))
	i += 1
	cnt += 1

for i in range(1, n+1):
	ans.append(str(i)+' '+str(i+1 if i+1 <= n else 1))

print(cnt)
print('\n'.join(ans))