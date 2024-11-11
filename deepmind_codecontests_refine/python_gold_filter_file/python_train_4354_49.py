n = int(input())
A = list(map(int, input().split()))

dp = [[0]*(n+1) for i in range(n+1)]

for d in range(1, n+1):
    for i in range(n+1-d):
        j = i+d
        if (n-d)%2 == 0:
            dp[i][j] = max(dp[i+1][j]+A[i], dp[i][j-1]+A[j-1])
        else:
            dp[i][j] = min(dp[i+1][j]-A[i], dp[i][j-1]-A[j-1])
print(dp[0][n])