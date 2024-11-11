(h,n),*c=[[*map(int,i.split())]for i in open(0)]
dp=[10**9]*(2*10**4+1)
c.sort()
dp[0]=0
for i in range(h):
    for a,b in c:
        if i+a<=2*10**4:
            dp[i+a]=min(dp[i+a],dp[i]+b)
        else:break    
print(min(dp[h:]))