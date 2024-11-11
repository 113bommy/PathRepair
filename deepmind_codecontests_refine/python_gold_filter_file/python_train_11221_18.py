inf = 10 ** 18
h, n = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(n)]
max_a = max(a for a, _ in ab)
dp = [inf] * (h + max_a)
dp[0] = 0
for i in range(1, h + max_a):
    dp[i] = min(dp[i-a] + b for a, b in ab)
print(min(dp[h:]))
