n,k = map(int,input().split())
H = list(map(int,input().split()))
dp = [10**10]*n
dp[0] = 0
for i in range(n):
	for j in range(1,k+1):
		if i+j < n:
			dp[i+j] = min(dp[i+j],dp[i]+abs(H[i+j]-H[i]))
print(dp[n-1])