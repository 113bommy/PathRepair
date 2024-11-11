H, N  = map(int, input().split())
dp = [float('inf')] * (H + 1)
dp[0] = 0
for i in range(N):
    a, b = map(int, input().split())
    for j in range(H):
        nj = min(j+a, H)
        dp[nj] = min(dp[nj], dp[j]+b)
print(dp[H])