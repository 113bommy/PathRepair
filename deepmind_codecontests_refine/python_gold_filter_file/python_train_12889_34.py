n, W = map(int, input().split())
dp = [W + 1] * (1010 * (n + 1))

dp[0] = 0
v_max = 0
for i in range(n):
    w, v = map(int, input().split())
    v_max += v
    for j in range(v_max, v - 1, -1):
        dp[j] = min(dp[j - v] + w, dp[j])

ans = 0
for i in range(v_max, -1, -1):
    if dp[i] <= W:
        ans = max(ans, i)
print(ans)