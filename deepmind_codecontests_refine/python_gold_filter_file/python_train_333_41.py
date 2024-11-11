n,k=map(int,input().split())
x=list(map(int,input().split()))
x.sort()
dp=[0]*n
ma,count=0,1
for i in range(n):
    if i>0 and x[i]==x[i-1]:
        count+=1
        ma=max(ma,count)
    else:
        count=1
    if i==0:dp[i]=x[i]
    else: dp[i]=dp[i-1]+x[i]
ans=123456789999990
for i in range(1,n):
    if i+1>=k:
        ans=min(ans,x[i]*i-dp[i-1]-(i+1-k))
    if n-i>=k:
        ans = min(ans,dp[n - 1]-dp[i]-x[i]*(n-i-1)-(n-i-k))
    ans=min(ans,x[i]*i-dp[i-1]+dp[n-1]-dp[i]-x[i]*(n-1-i)-(n-k))
if ma>=k:ans=0
if n==1:ans=0
print(max(ans,0))