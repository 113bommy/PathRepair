 ######      ###      #######    #######    ##      #     #####        ###     ##### 
 #     #    #   #          #        #       # #     #    #     #      #   #     ###  
 #     #   #     #        #         #       #  #    #   #       #    #     #    ###  
 ######   #########      #          #       #   #   #   #           #########    #   
 ######   #########     #           #       #    #  #   #           #########    #   
 #     #  #       #    #            #       #     # #   #    ####   #       #    #   
 #     #  #       #   #             #       #      ##   #    #  #   #       #        
 ######   #       #  #######     #######    #       #    #####  #   #       #    #   

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

class rmq:
	def __init__(self, a):
		tab = [a.copy()]
		n = int(log2(len(a)))
		while len(tab) <= n:
			d = 1<<(len(tab)-1)
			temp = []
			i = 0
			while i+d < len(tab[-1]):
				temp.append(min(tab[-1][i], tab[-1][i+d]))
				i += 1
			tab.append(temp)

		self.tab = tab

	def query(self, l, r):
		d = int(log2(r-l+1))
		x = r+1-(1<<d)
		return min(self.tab[d][l], self.tab[d][x])


class lca:
		def __init__(self, adj, n):
			eur = []
			stack = [1]
			getId, getNode = [0]*(n+1), [0]*(n+1)
			idx = [0]*(1+n)
			cId = 1

			while stack:
				p = stack[-1]
				if getId[p] == 0:
					getId[p] = cId
					getNode[cId] = p
					cId += 1
					idx[p] = len(eur)
				eur.append(getId[p])

				if adj[p] and getId[adj[p][-1]]: 
					adj[p].pop()
				elif adj[p]:
					stack.append(adj[p].pop())
				else:
					stack.pop()

			self.rmq_ = rmq(eur)
			self.getNode, self.getId = getNode, getId
			self.idx = idx


		def query(self, l, r):
			# lca of l and r
			l, r = self.idx[l], self.idx[r]
			if r < l:
				l, r = r, l
			p = self.getNode[self.rmq_.query(l, r)]
			return p








# find depth 
def getDepth(adj, n):
	stack = [1]
	d = [0]*(n+1)
	d[1] = 1
	while stack:
		p = stack.pop()
		for c in adj[p]:
			if d[c] == 0: 
				stack.append(c)
				d[c] = d[p] + 1
	return d




n, q = gil()
adj = [[] for _ in range(n+1)]
for _ in range(n-1):
	x, y = gil()
	adj[x].append(y)
	adj[y].append(x)


depth = getDepth(adj, n)
lca_ = lca(adj, n)


for _ in range(q):
	q_ = gil()[1:]
	l = max(q_, key=lambda x :depth[x])
	ans = "YES"
	for r in q_:
		p = lca_.query(l, r)
		# print(l, r, p)
		if abs(depth[p] - depth[r]) > 1:
			ans = "NO"
			break


	print(ans)