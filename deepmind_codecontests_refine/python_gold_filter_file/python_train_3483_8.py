
t, k = map(int, input().split())

# print("t is " + str(t) + " and k " + str(k))

N = 100005
P = 1000*1000*1000+7

dp = [0 for _ in range(N)]

dp[0] = 1

for i in range(N):
	if i < k:
		dp[i] = 1
	else:
		dp[i] = (dp[i-k]+dp[i-1])%P;

for i in range(1,N):
	dp[i] = (dp[i] + dp[i-1])%P

for _ in range(t):
	a, b = map(int, input().split())
	print((dp[b]-dp[a-1]+P)%P)