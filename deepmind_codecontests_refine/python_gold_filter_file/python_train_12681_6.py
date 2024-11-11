s=input()
t=input()
n,m=len(s),len(t)
dp=[[0]*(m+1) for i in range(n+1)]
dp[0][0]=1

for i in range(n+1):
    for j in range(m+1):
        dp[i][j]=max(dp[i][j-1],dp[i-1][j])
        if i*j!=0 and s[i-1]==t[j-1]:
            dp[i][j]=max(dp[i-1][j-1]+1,dp[i][j])

ans=""
i,j=n,m
while 0<i and 0<j:
    if dp[i][j]==dp[i-1][j]:
        i-=1
    elif dp[i][j]==dp[i][j-1]:
        j-=1
    else:
        ans+=s[i-1]
        i-=1
        j-=1

print(ans[::-1])



