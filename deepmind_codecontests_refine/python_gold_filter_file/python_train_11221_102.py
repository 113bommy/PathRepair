H, N = map(int, input().split())
inf = 1 << 32
dp = [inf] * (H + 1)
dp[0] = 0
for i in range(N):
    a,b = map(int, input().split())
    for j in range(H+1):
        dp[min(H,j + a)] = min(dp[min(H,j + a)], dp[j] + b)
print(dp[H])