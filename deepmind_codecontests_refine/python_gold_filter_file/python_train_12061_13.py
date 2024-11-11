N, W = (int(i) for i in input().split())
w = [0]*N
v = [0]*N
for i in range(N):
  w[i], v[i] = (int(j) for j in input().split())
w0 = w[0]
wh = [a - w0 for a in w]
dp = [[[-1]*(N+1) for i in range(3*N+1)] for j in range(N+1)]
dp[0][0][0] = 0
for i in range(N):
  for j in range(3*N+1):
    for k in range(N+1):
      if dp[i][j][k] != -1:
        dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k])
      if j - wh[i] >=0 and k-1 >=0 and dp[i][j-wh[i]][k-1] != -1:
        dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j-wh[i]][k-1]+v[i])
res = 0
for j in range(3*N+1):
  for k in range(N+1):
    if j + w0*k <= W:
      res = max(dp[N][j][k], res)
print(res)
