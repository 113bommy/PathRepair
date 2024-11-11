MOD = 10**9+7
n, c = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

sig = [[0 for _ in range(max(b)+1)] for _ in range(c+1)]
for i in range(c+1):
	for j in range(1, max(b)+1):
		sig[i][j] = sig[i][j-1] + pow(j, i, MOD)
		sig[i][j] %= MOD

def sigma(C, A, B):
	return (sig[C][B] - sig[C][A-1]) % MOD

dp = [[0 for _ in range(c+1)] for _ in range(n)]
for j in range(c+1):
	dp[0][j] = sigma(j, a[0], b[0])

for i in range(1, n):
	for j in range(c+1):
		for k in range(j+1):
			dp[i][j] += dp[i-1][k] * sigma(j-k, a[i], b[i])
			dp[i][j] %= MOD

print(dp[n-1][c])