MOD = 10**9+7
n = int(input())
S = input()
def main():
  dp = [[0]*(n+1) for _ in range(n+1)]
  for j in range(n):
    dp[1][j] = 1
  for i, s in enumerate(S, 1):
    if s == "<":
      dp[i+1][n-(i+1)] = dp[i][n-i]
      for j in range(n-i-2, -1, -1):
        dp[i+1][j] = dp[i+1][j+1] + dp[i][j+1]
        dp[i+1][j] %= MOD
    else:
      dp[i+1][0] = dp[i][0]
      for j in range(1, n-i):
        dp[i+1][j] = dp[i+1][j-1] + dp[i][j]
        dp[i+1][j] %= MOD
  ans = dp[n][0]
  print(ans)
if __name__ == "__main__":
  main()