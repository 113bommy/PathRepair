def solve():
    input()
    n, k = [int(i) for i in input().split()]
    a = [int(i) for i in input().split()]
    t = [int(i) for i in input().split()]
    dp = [10 ** 10 for i in range(n + 1)]
    for i in range(k):
        dp[a[i]] = t[i]
    for i in range(1, len(dp)):
        dp[i] = min(dp[i - 1] + 1, dp[i])
    for i in range(len(dp) - 2, 0, -1):
        dp[i] = min(dp[i + 1] + 1, dp[i])
    print(*dp[1:])

for _ in range(int(input())):
    solve()