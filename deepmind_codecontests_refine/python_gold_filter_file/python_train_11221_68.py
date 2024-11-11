h,n,*L=map(int,open(0).read().split())
dp=[float('inf')]*(h+10100)
dp[0]=0
for a,b in zip(*[iter(L)]*2):
    for i in range(h):
        t=dp[i]+b
        if t<dp[i+a]:
            dp[i+a]=dp[i]+b
print(min(dp[h:]))