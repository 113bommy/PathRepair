n, k = map(int, input().split())
a_list = [int(input()) for _ in range(n)]

dp = [1] * n

for i in range(n):
    for j in range(max(0, i - 100), i):
        if abs(a_list[i] - a_list[j]) <= k:
            dp[i] = max(dp[i], dp[j] + 1)

ans = max(dp)
print(ans)