import sys
sys.setrecursionlimit(10**6)
def input():
	return sys.stdin.buffer.readline()[:-1]

n, m = map(int, input().split())
adj = [[] for _ in range(n)]
for _ in range(n-1):
	a, b = map(int, input().split())
	adj[a-1].append(b-1)
	adj[b-1].append(a-1)

dp = [1 for _ in range(n)]
def dfs1(x, p):
	for c in adj[x]:
		if c == p:
			continue
		dfs1(c, x)
		dp[x] *= dp[c]+1
		dp[x] %= m
	return

dfs1(0, -1)
ans = [0 for _ in range(n)]
ans[0] = dp[0]
def dfs2(x, p):
	l = len(adj[x])
	cuml = [1 for _ in range(l+2)]
	cumr = [1 for _ in range(l+2)]
	for i in range(l):
		cuml[i+1] = (cuml[i] * (dp[adj[x][i]] + 1)) % m
	for i in range(l-1, -1, -1):
		cumr[i+1] = (cumr[i+2] * (dp[adj[x][i]] + 1)) % m
	pres_x = dp[x]
	for i, c in enumerate(adj[x]):
		if c == p:
			continue
		pres_c = dp[c]
		dp[x] = (cuml[i] * cumr[i+2]) % m
		dp[c] *= dp[x] + 1
		dp[c] %= m
		ans[c] = dp[c]
		dfs2(c, x)
		dp[x] = pres_x
		dp[c] = pres_c
	return

dfs2(0, -1)
print(*ans, sep="\n")