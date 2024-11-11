n,k=map(int,input().split())
s=list(map(int,input().split()))
s1=list(map(int,input().split()))
dp=[[[0 for j in range(10**5)] for l in range(2)] for i in range(n+1)]
y=s[0]-s1[0]*k
if y>=0:
    dp[0][0][y]=s[0]
else:
    dp[0][1][-y]=s[0]
for i in range(1,n):
    y=s[i]-s1[i]*k
    for j in range(100**2+2):
        for l in range(2):
            dp[i][l][j]=max(dp[i][l][j],dp[i-1][l][j])
            if dp[i-1][l][j]!=0 or (j==0):
                if l==1:
                    x=-j+y
                else:
                    x=j+y
                if x<0:
                    x=abs(x)
                    dp[i][1][x]=max(dp[i-1][1][x],dp[i][1][x],dp[i-1][l][j]+s[i])
                else:
                    dp[i][0][x]=max(dp[i-1][0][x],dp[i][0][x],dp[i-1][l][j]+s[i])
if dp[n-1][0][0]==0:
    print(-1)
else:
    print(dp[n-1][0][0])
