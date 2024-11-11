N = int(input())
A = list(map(int, input().split()))

cum = [[0]*(N) for i in range(N)]
for i in range(N):
  c = 0
  for j in range(i, N):
    c += A[j]
    cum[i][j] = c

dp = [[0]*N for i in range(N)]

for n in range(1, N+1):
  for i in range(N-n):
    j = i + n
    min_cost = 0
    for k in range(i, j):
      if min_cost == 0:
        min_cost = dp[i][k] + dp[k+1][j]
      else:
        min_cost = min(min_cost, dp[i][k]+dp[k+1][j])
    
    dp[i][j] = min_cost + cum[i][j]

print(dp[0][N-1])