N,Ma,Mb=map(int,input().split())
dp=[[[10**9]*401 for i in range(401)] for i in range(N)]
for i in range(N):
  a,b,c=map(int,input().split())
  if i==0:
    dp[0][a][b]=c
    dp[0][0][0]=0
  else:
    for p in range(401):
      for q in range(401):
        if p>=a and q>=b:
          dp[i][p][q]=min(dp[i-1][p][q],dp[i-1][p-a][q-b]+c)
        else:
          dp[i][p][q]=dp[i-1][p][q]
ans=10**9
for a in range(1,401):
  if Mb*a/Ma<=400 and Mb*a%Ma==0:
    ans=min(ans,dp[N-1][a][Mb*a//Ma])
if ans==10**9:
  print(-1)
else:
  print(ans)