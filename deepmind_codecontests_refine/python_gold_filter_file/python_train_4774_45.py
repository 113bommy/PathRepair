n,ma,mb=map(int,input().split())
dpn=400001
dp=[10**6]*dpn
dp[0]=0
for i in range(n):
    a,b,c=map(int,input().split())
    for j in range(dpn-1,-1,-1):
        if j==0 or dp[j]!=10**6:
            dp[j+a*1000+b]=min(dp[j+a*1000+b],dp[j]+c)
ans=10**6
s=1000*ma+mb
p=1
while s*p<dpn:
    ans=min(ans,dp[s*p])
    p+=1
if ans==10**6:
    print(-1)
else:
    print(ans)
