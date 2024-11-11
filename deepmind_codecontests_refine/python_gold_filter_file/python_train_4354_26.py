import sys
readline = sys.stdin.readline

N = int(readline())
A = list(map(int,readline().split()))

# dp[i][j] = 元の数列の中の連続する区間i～jに対して、最終局面に行った時のX-Yの最大値

dp = [[0] * (N + 1) for i in range(N + 1)]
  
for length in range(1, N + 1):
  for i in range(N - length + 1):
    j = i + length
    
    if (N - length) % 2 == 0: # 先手番
      dp[i][j] = max(dp[i + 1][j] + A[i], dp[i][j - 1] + A[j - 1])
      
    else: # 後手番
      dp[i][j] = min(dp[i + 1][j] - A[i], dp[i][j - 1] - A[j - 1])

print(dp[0][N]) 