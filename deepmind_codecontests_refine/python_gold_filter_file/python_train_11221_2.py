f=lambda:map(int,input().split())
h,n=f()
dp=[0]+[10**9]*h
for i in range(n):
  a,b=f()
  for j in range(h+1): dp[j]=min(dp[j],dp[max(j-a,0)]+b)
print(dp[h])