N = int(input())
S = input()
dp = [[0]*N for i in range(N)]
pm = 0
ans = 0
for i in range(N-1,0,-1):
  for j in range(i-1,-1,-1):
    if S[i]==S[j]:
      if i<N-1:
        dp[i][j] = min(dp[i+1][j+1]+1, i-j)
      else:
        dp[i][j] = 1
    else:
      dp[i][j] = 0
    if dp[i][j]>ans:
      ans = dp[i][j]
print(ans)