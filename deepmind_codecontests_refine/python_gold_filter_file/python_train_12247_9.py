n, d = map(int, input().split())
s = input()
dp = [0] * n
for i in range(n):
    if int(s[i]) == 0:
        dp[i] = 100000
for i in range(d + 1):
    if int(s[i]) != 0:
        dp[i] = 1
for i in range(d + 1, n):
    if int(s[i]) != 0:
        dp[i] = min(dp[i - d:i]) + 1
if dp[n - 1] < 1000:
    print(dp[n - 1])
else:
    print(-1)

