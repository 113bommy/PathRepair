import sys
input=sys.stdin.readline
s=' '+input().rstrip()
t=' '+input().rstrip()
m=len(s)-1
n=len(t)-1
dp=[[0]*(n+1) for i in range(m+1)]
for i in range(1,m+1):
    for j in range(1,n+1):
        if s[i]==t[j]:
            dp[i][j]=dp[i-1][j-1]+1
        else:
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])
ans=''
while m>0 and n>0:
    if dp[m][n]==dp[m][n-1]:
        n-=1
    elif dp[m][n]==dp[m-1][n]:
        m-=1
    elif dp[m][n]==dp[m-1][n-1]+1:
        ans=s[m]+ans
        m-=1
        n-=1
print(ans)