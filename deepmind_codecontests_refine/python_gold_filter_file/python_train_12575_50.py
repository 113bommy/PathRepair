n=int(input())
s=input()
dp=[[0]*n for _ in range(n)]
ans=0
for i in range(n-1,-1,-1):
    for j in range(n-1,i,-1):
        if s[i]==s[j]:
            dp[i][j]=dp[i+1][j+1]+(i+1+dp[i+1][j+1]!=j+1) if j<n-1 else 1
    ans=max(ans,max(dp[i]))
print(ans)