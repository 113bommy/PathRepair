h, n = map(int, input().split())
ab = tuple(tuple(map(int, input().split())) for _ in range(n))

dp = [10 ** 20] * 10 ** 4 * 2
dp[0] = 0
for a, b in ab:
    for i in range(h):
        dp[i + a] = min(dp[i + a], dp[i] + b)
print(min(dp[h:]))