def f(a):
	s="hard"
	dp=[[float("inf")]*5 for i in range(len(a)+1)]
	dp[0][0]=0
	for i in range(len(a)):
		for j in range(4):
			dp[i+1][j+(s[j]==a[i][1])]=min(dp[i+1][j+(s[j]==a[i][1])],dp[i][j])
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]+a[i][0])
	return min(dp[len(a)][:4])
n=int(input())
s=list(input())
cost=[*map(int,input().strip().split())]
a=[*zip(cost,s)]
print(f(a))