mod=998244353
n,s=map(int,input().split())
a=list(map(int,input().split()))
dp=[[0]*(s+1) for _ in range(n+1)]
dp[0][0]=1
for i in range(n):
	for j in range(s+1):
		dp[i+1][j]+=2*dp[i][j]
		dp[i+1][j]%=mod
		if j+a[i]<=s:
			dp[i+1][j+a[i]]+=dp[i][j]
			dp[i+1][j+a[i]]%=mod
print(dp[n][s])