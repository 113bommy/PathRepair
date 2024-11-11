h,n=map(int,input().split())
l=[]
s=0
for i in range(n):
    a,b=map(int,input().split())
    s=max(s,a)
    l.append((a,b))
dp=[10**10]*(h+s)
dp[0]=0
for i in range(h):
    for s,t in l:
        dp[i+s]=min(dp[i]+t,dp[i+s])
print(min(dp[h:]))
