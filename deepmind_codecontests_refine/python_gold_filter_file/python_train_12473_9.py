n=int(input())
h=list(map(int,input().split()))
dp=[0]*n
dp[0]=0
dp[1]=abs(h[1]-h[0])
for i in range(n-2):
  dp[i+2]=min(dp[i]+abs(h[i+2]-h[i]),dp[i+1]+abs(h[i+2]-h[i+1]))
print(dp[n-1])
