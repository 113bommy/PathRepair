N,S = list(map(int, input().split()))
A = list(map(int, input().split()))
mod = 998244353

dp = [[0 for i in range(S+1)] for _ in range(N+1)]
# dp[i][j] Aiまでを使って、合計jを作る作り方
dp[0][0] = 1

for i in range(1,N+1):
  a = A[i-1]
  for j in range(S+1):
    dp[i][j] += dp[i-1][j] * 2
    dp[i][j] %= mod
    if j+a <= S :
      dp[i][j+a] += dp[i-1][j]
      dp[i][j+a] %= mod
print(dp[N][S])