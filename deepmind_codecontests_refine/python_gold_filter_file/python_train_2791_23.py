n,k=map(int,input().split())
h=list(map(int,input().split()))
dp=[0]*n

for i in range(1,n):
    dp[i]=min(dp[j] + abs(h[j]-h[i]) for j in range(max(0,i-k),i))

print(dp[-1])