n=int(input())
a=list(map(int,input().split()))

dp=[[0]*(n) for i in range(n)]

if n%2!=0:
    for i in range(n):
        dp[i][i]=a[i]
else:
    for i in range(n):
        dp[i][i]=-a[i]
    

for i in range(n-1)[::-1]:
    for g in range(i,n):
        if (i+g)%2!=n%2:
            dp[i][g]=max(dp[i][g-1]+a[g],dp[i+1][g]+a[i])
        else:
            dp[i][g]=min(dp[i][g-1]-a[g],dp[i+1][g]-a[i])

print(dp[0][n-1])