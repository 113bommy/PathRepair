N,W=map(int,input().split())
oj=[]
for i in range(N):
  oj.append(list(map(int,input().split())))
M=100*1001
dp=[10**10]*M
dp[0]=0
for i in range(N):
  for j in range(M,-1,-1):
    if j+oj[i][1]<M:
      k=j+oj[i][1]
      dp[k]=min(dp[k],dp[j]+oj[i][0])
v=0
for i in range(M):
  if dp[i]<=W:v=i
print(v)
