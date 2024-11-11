N, Ma, Mb = map(int, input().split())
table = []
for i in range(N):
  a,b,c = map(int, input().split())
  table.append([a,b,c])
inf = 10**9
dp = [[[inf]*401 for i in range(401)] for i in range(N+1)]
dp[0][0][0] = 0

for i in range(1,N+1):
  a,b,c = table[i-1]
  for j in range(401):
    for k in range(401):
      dp[i][j][k] = dp[i-1][j][k]
      if 400>=j-a>=0 and 400>=k-b>=0:
        dp[i][j][k] = min(dp[i-1][j][k],dp[i-1][j-a][k-b]+c)
ans = 10**9
i = 1
while max(Ma,Mb)*i <= 400:
  ans = min(ans,dp[N][Ma*i][Mb*i])
  i += 1
if ans == 10**9:
  ans = -1
print(ans)