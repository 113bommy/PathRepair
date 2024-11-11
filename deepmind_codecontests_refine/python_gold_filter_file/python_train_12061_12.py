N,W=map(int,input().split())
wv=[]
for i in range(N):
    a,b=map(int,input().split())
    wv.append((a,b))
if wv[0][0]<300:
    dp=[[0]*(30000+1) for i in range(N+1)]
    for i in range(1,N+1):
        wi,vi=wv[i-1]
        for j in range(1,30000+1):
            dp[i][j]=dp[i-1][j]
            if j-wi<0:
                continue
            dp[i][j]=max(dp[i-1][j-wi]+vi,dp[i][j])
    ans=dp[N][W]
    print(ans)
    quit()
dp=[[0]*(301*101) for i in range(N+1)]
d=wv[0][0]
def change(n):
    return 301*(n//d)+min(n%d,300)
#if change(W)>301*101:
#    quit()
for i in range(1,N+1):
    wi,vi=wv[i-1]
    z=301+(wi-d)
    for j in range(1,301*101):
        dp[i][j]=dp[i-1][j]
        if j-z<0:
            continue

        dp[i][j]=max(dp[i-1][j-z]+vi,dp[i][j])
ans=dp[N][change(W)]
print(ans)
