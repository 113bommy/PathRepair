import sys
sys.setrecursionlimit(10**6)

n, m = map(int, input().split())
adj = [[] for _ in range(n)]
parity = [-1 for _ in range(n)]
valid = True

def dfs(x):
	global valid
	p = parity[x]
	for v in adj[x]:
		if parity[v] < 0:
			parity[v] = 1^p
			dfs(v)
		elif parity[v] == p:
			valid = False
			return
	return

for _ in range(m):
	a, b = map(int, input().split())
	adj[a-1].append(b-1)
	adj[b-1].append(a-1)

parity[0] = 0
dfs(0)
if not valid:
	print((n*(n-1)//2) - m)
else:
	o = sum(parity)
	print(o*(n-o) - m)