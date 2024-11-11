n,*a=map(int,open(0).read().split())
dp=[[0]*(n+1) for _ in range(n+1)]
for l in range(n)[::-1]:
	for r in range(n)[::-1]:
		if l+r<=n-1:
			dp[l][r]=max(a[l]-dp[l+1][r],a[n-1-r]-dp[l][r+1])
print(dp[0][0])