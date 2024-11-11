H,N=map(int,input().split())
dp = [10**10]*(H+1)
dp[0]=0
for _ in range(N):
    A,B=map(int,input().split())
    for idx in range(H):
        nidx = min(idx+A,H)
        dp[nidx]=min(dp[nidx],dp[idx]+B)
print(dp[-1])
