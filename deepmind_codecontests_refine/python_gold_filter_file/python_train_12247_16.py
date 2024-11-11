n, d = map(int, input().split())
w = input()
dp = [101] * (n + d)
dp[d] = 0

for i in range(d + 1, len(dp)):
    if int(w[i - d]) == 1:
        sr = dp[i - d:i]
        dp[i] = min(dp[i - d:i] + [101]) + 1
if dp[-1] >= 101:
    print(-1)
else:
    print(dp[-1])
