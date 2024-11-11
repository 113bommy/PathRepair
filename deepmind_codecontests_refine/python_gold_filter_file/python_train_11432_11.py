MOD = 10**9 + 7

N,X = map(int,input().split())
S = list(map(int,input().split()))
S.sort()
S = [None] + S
dp = [[0 for i in range(X+1)] for j in range(N+1)]
dp[1] = [i % S[1] for i in range(X+1)]
for n in range(2, N+1):
	for x in range(X+1):
		dp[n][x] = (dp[n-1][x] * (n-1) + dp[n-1][x%S[n]]) % MOD
print(dp[N][X])