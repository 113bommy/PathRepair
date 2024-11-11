n,a,b,c = map(int,input().split(" "))

dp = [0]+[-4005]*4005

for i in range(min(a,b,c),n+1):
	dp[i] = max(dp[i-a],dp[i-b],dp[i-c]) + 1


print(dp[n])