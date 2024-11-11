# 大きさがsum(a)のスライムが1匹いる
# dp[l][r]=min(区間[l,r]を分解するための最小コスト)
n=int(input())
a=list(map(int,input().split()))
INF=10**15
dp=[[0]*n for i in range(n)]
for i in range(n):
    dp[i][i]=a[i]
for i in range(n-1):
    for j in range(i+1,n):
        dp[i][j]=dp[i][j-1]+a[j]

for i in range(n-1):
    for j in range(i+1,n):
        ans=INF
        # print(j-i-1,j)
        for k in range(j-i-1,j):
            ans=min(ans,dp[j-i-1][k]+dp[k+1][j])
        if i<n-2:
            dp[j-i-1][j]+=ans
        else:
            print(ans)