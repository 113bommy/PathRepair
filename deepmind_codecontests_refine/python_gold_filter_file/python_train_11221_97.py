h, n = map(int, input().split())

f_inf = float("inf")
dp = [f_inf] * (h + 1)
dp[0] = 0
for i in range(n):
    a, b = map(int, input().split())
    for j in range(h):
        next_j = min(j + a, h)
        dp[next_j] = min(dp[next_j], dp[j] + b)

print(dp[h])