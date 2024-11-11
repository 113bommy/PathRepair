N = int(input())
A =list(map(int,input().split()))

dp = [[0]*N for i in range(N)]

for i,a in enumerate(A) :
    dp[i][i] = a

for i in range(N-2, -1, -1) :
    for j in range(i+1, N) :
        left = A[i] - dp[i+1][j]
        right = A[j] - dp[i][j-1]
        dp[i][j] = max(left, right)

ans = dp[0][N-1]

print(ans)
