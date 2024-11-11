from collections import defaultdict
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inpl(): return list(map(int, input().split()))
def inpl_s(): return list(input().split())

K = int(input())


lines = defaultdict(set)
for i in range(K-1):
	lines[i].add((i+1,1))
lines[K-1].add((0,1))

for s in range(K):
	t = s*10 % K
	if s != t:
		lines[s].add((t,0))

def search (s,w_0): #s->t
	global weight
	global q

	for line in list(lines[s]):
		t = line[0]
		w = w_0 + line[1]
		if weight[t] > w:
			heapq.heappush(q, [w,t])
			weight[t] = w

s = 1
weight = [INF]*K
weight[s] = 0
q = [[0,s]]
heapq.heapify(q)
while q:
	w,n = heapq.heappop(q)
	search(n,w)

print(weight[0]+1)
