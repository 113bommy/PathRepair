import sys
sys.setrecursionlimit(65536)

N,M=map(int, input().split())
bridge=[[int(x) for x in input().split()] for _ in range(M)]

uf=[i for i in range(N+1)]
nc=[1 for i in range(N+1)]

def find(i):
	if uf[i] == i:
		return i
	else:
		uf[i] = find(uf[i])
		return uf[i]

def union(i, j):
	gi, gj = find(i), find(j)
	if gi != gj:
		uf[gi] = gj
		diff = nc[gj] * nc[gi]
		nc[gj] += nc[gi]
		return diff
	return 0

su = N*(N-1)//2
ans = [-1]*M

for i in range(M-1, -1, -1):
	ans[i] = su
	x,y = bridge[i]
	su -= union(x, y)

print("\n".join(map(str, ans)))
