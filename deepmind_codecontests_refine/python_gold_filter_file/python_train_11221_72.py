INF = 2**60 # 無限大を表す値
H, N = map(int, input().split())
AB = [map(int, input().split()) for i in range(N)]
dp = [INF] * (H + 1)
dp[0] = 0
for A, B in AB:
    for j in range(H+1):
        dp[j] = min(dp[j], dp[max(j-A, 0)] + B)
print(dp[H])