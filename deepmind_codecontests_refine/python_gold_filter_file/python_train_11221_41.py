H,N=map(int,input().split())
ab=[list(map(int,input().split())) for _ in range(N)]
x=max(a for a,b in ab)
dp=[0]*(H+x)
for i in range (1,H+x):
    dp[i]=min(dp[i-a]+b for a,b in ab)
print(min(dp[H:]))