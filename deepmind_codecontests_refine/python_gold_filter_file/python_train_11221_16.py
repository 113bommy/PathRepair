h, n, *L = map(int, open(0).read().split())
dp = [0] * (h + 99999)
for i in range(1, h + 1):
    dp[i] = min(dp[i - a] + b for a, b in zip(*[iter(L)] * 2))

print(dp[h])
