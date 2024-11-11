n = int(input())
dp = [0, 0] + [n] * (n - 1) + [0]
a = tuple(map(int, input().split()))
i, q = 0, [1]
while i < n:
    v = q[i]
    i += 1
    if dp[v - 1] == n:
        q.append(v - 1)
    dp[v - 1] = min(dp[v - 1], dp[v] + 1)
    if dp[v + 1] == n:
        q.append(v + 1)
    dp[v + 1] = min(dp[v + 1], dp[v] + 1)
    if dp[a[v - 1]] == n:
        q.append(a[v - 1])
    dp[a[v - 1]] = min(dp[a[v - 1]], dp[v] + 1)
print(*dp[1:-1])
