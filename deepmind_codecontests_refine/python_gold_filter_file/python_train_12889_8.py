n,W=map(int,input().split())
wv=[[int(i) for i in input().split()]for _ in range(n)]
dp=[W+1]*(10**5+1)
dp[0]=0
for i in range(0,n):
    w,v = wv[i]
    for j in range(10**5,v-1,-1):
        dp[j]=min(dp[j],dp[j-v]+w)
for i in range(10**5,-1,-1):
    if dp[i]<=W:
        print(i)
        break