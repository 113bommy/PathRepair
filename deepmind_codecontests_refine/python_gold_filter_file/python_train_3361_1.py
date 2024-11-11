for _ in range(int(input())):
	n=int(input())
	t=sorted(list(map(int,input().split())))
	m=max(max(t)*2,n+1)
	dp=[[100000000]*(m+1) for i in range(n)]
	for j in range(1,m+1):
		dp[0][j]=abs(t[0]-j)
	for i in range(1,n):
		for j in range(2,m+1):
			if i<=j:
				dp[i][j]=abs(t[i]-j)+min(dp[i-1][:j])
	print(min(dp[-1]))