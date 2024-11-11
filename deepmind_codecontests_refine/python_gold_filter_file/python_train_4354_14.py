N = int(input())
A = [int(a) for a in input().split()]
dp = [[0] * (N+1) for _ in range(N+1)]

for d in range(N):
    for l in range(N-d):
        r = l + d
        if d == 0:
            dp[l][r] = A[l] * (-1)**(N+d+1)
            
        else:
            s = (-1)**(N+d+1)
            dp[l][r] = max(A[l] + dp[l+1][r] * s, A[r] + dp[l][r-1] * s) * s

print(dp[0][N-1])