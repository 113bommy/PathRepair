MOD = 998244353

N, S = map(int, input().split())
A = list(map(int, input().split()))

dp = [[0] * (S + 1) for i in range(N)]
dp[0][0] = 2
if A[0] < S + 1:
	dp[0][A[0]] = 1

for i in range(1, N):
	for j in range(S + 1):
		dp[i][j] = (2 * dp[i - 1][j]) % MOD
		if 0 <= j - A[i] <= S:
			dp[i][j] = (dp[i][j] + dp[i - 1][j - A[i]]) % MOD
print(dp[-1][-1])