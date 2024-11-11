from math import *
from collections import *
from operator import itemgetter
import bisect
from heapq import *
i = lambda: input()
ii = lambda: int(input())
iia = lambda: list(map(int,input().split()))
isa = lambda: list(input().split())
I = lambda:list(map(int,input().split()))
chrIdx = lambda x: ord(x)-96
idxChr = lambda x: chr(96+x)

t = ii()

for _ in range(t):
	n = ii()
	a = iia()
	a.sort()
	d = dict(Counter(a))
	#print(d)
	g = 1
	ex = 0
	ey = 0
	for i in a:
		if(g+ex>=i):
			g+=1
			g+=ey
			ex = 0
			ey = 0
		else:
			ex+=1
			ey+=1
	print(g)