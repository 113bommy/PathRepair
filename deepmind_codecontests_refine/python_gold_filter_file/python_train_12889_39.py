n=0
W=0
n,W=map(int,input().split())
dp=[W+1]*101010
dp[0]=0
for i in range(n):
    w,v=map(int,input().split())
    j=100000
    while j>=0:
        if dp[j+v]>dp[j]+w:
            dp[j+v]=dp[j]+w
        j-=1
ans=0
for v in range(len(dp)):
    if dp[v]<=W:
        ans=v
print(ans)