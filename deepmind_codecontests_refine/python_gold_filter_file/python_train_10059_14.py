import sys
input=sys.stdin.readline
s=list(input().rstrip())
n=len(s)
dp=[[0 for i in range(n+1)] for j in range(n+1)]
dp[0][0]=int(s[0]=='a')
for i in range(1,n):
    if s[i]=='a':
        dp[0][i]=dp[0][i-1]+1
    else:
         dp[0][i]=dp[0][i-1]
for i in range(n):
    for j in range(i,n):
            dp[i][j]=dp[0][j]-dp[0][i-1]
maxi=0        
for i in range(n):
    for j in range(i+1,n):
        maxi=max(maxi,dp[0][i]+(j-i+1)-dp[i][j]+dp[j][n-1])
print(maxi if n>2 else n)        