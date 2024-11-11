N,K=map(int,input().split())
h=list(map(int,input().split()))
dp=[0]*N
dp[0]=0
dp[1]=abs(h[0]-h[1])
for i in range(2,N):
  dp[i] = min( dp[j] + abs(h[i]-h[j]) for j in range(max(0,i-K),i) )
print(dp[-1])