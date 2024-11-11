N = int(input())
a = list(map(int,input().split()))
X,Y = 0,0
dp = [[0] * (N+1) for i in range(N+1)]
# dp[i][j] ans = dp[1][N]
for i in range(1,N+1):
    if N % 2 == 1:
        dp[i][i] = a[i-1]
    else:
        dp[i][i] = -a[i-1]
for i in range(N-1,0,-1):
    for j in range(1,N+1):
        if i >= j: continue
        if (j - i) % 2 != N % 2:
            dp[i][j] = max(a[i-1] + dp[i+1][j],a[j-1] + dp[i][j-1])
        else:
            dp[i][j] = min(-a[i-1] + dp[i+1][j],-a[j-1] + dp[i][j-1])
print(dp[1][N])