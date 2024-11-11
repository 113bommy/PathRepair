N = int(input())
A = list(map(int, input().split()))

dp = [[0]*N for i in range(N)]

for i, a in enumerate(A):
  dp[i][i] = a

for i in range(1, N):
  for j in range(i-1, -1, -1):
    dp[i][j] = max(A[i]-dp[i-1][j], A[j]-dp[i][j+1])

print(dp[N-1][0])