N = int(input())
A = [int(a) for a in input().split()]

dp = [[0]*N for _ in range(N)]
        
for k in range(N):
    for i in range(N-k):
        if k == 0:
            dp[i][i] = A[i]
            continue
    
        dp[i][i+k] = max(A[i]-dp[i+1][i+k], A[i+k]-dp[i][i+k-1])

print(dp[0][N-1])