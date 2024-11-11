N, S = map(int, input().split())
A = list(map(int, input().split()))
MOD = 998244353

def main():
  dp = [0]*(S+1)
  dp[0] = 1
  for i in range(1, N+1):
    p = [0]*(S+1)
    dp, p = p, dp
    for j in range(0, S+1):
      dp[j] += 2*p[j]
      dp[j] %= MOD
      if j-A[i-1] >= 0:
        dp[j] += p[j-A[i-1]]
        dp[j] %= MOD
  print(dp[S])

if __name__ == "__main__":
  main()