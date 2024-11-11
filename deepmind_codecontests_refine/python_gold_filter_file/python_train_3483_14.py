t, k = map(int, input().split())
dp = [0 for x in range(100001)]

for x in range(1,k + 1):
	dp[x] = 1
dp[k] += 1

for x in range(k + 1, 100001):
	dp[x] = (dp[x-1] + dp[x - k])%1000000007

for x in range(2,100001):
	dp[x] = (dp[x] + dp[x-1])%1000000007

for x in range(t):
	a, b = map(int, input().split())
	print(dp[b] - dp[a-1] if dp[b] >= dp[a-1] else dp[b] - dp[a-1] + 1000000007)