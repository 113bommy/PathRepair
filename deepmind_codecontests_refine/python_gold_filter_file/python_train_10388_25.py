import sys
sys.setrecursionlimit(200000)
from collections import deque
from bisect import bisect_left

N = int(input())
A = list(map(int, input().split()))
adj = [[] for i in range(N)]
for i in range(N - 1):
	u, v = map(int, input().split())
	adj[u - 1].append(v - 1)
	adj[v - 1].append(u - 1)


INF = 10 ** 10
done = [False] * N
done[0] = True
lisdp = [INF] * N
lisdp[0] = A[0]
change = [[-1, INF] for i in range(N)] #index, original
change[0] = [0, INF]
lisl = [0] * N
lisl[0] = 1

def dfs(v):
	for nv in adj[v]:
		if done[nv]:
			continue
		done[nv] = True
		ind = bisect_left(lisdp, A[nv])
		ori = lisdp[ind]
		change[nv] = [ind, ori]
		if ori == INF:
			lisl[nv] = lisl[v] + 1
		else:
			lisl[nv] = lisl[v]
		lisdp[ind] = A[nv]
		dfs(nv)
	lisdp[change[v][0]] = change[v][1]

dfs(0)
for i in range(N):
	print(lisl[i])	