def calc(pos, time):
    if pos == n - 1: return abs(a[n - 1] - time)
    if time > 405: return 1 << 30
    if dp[pos][time] != -1: return dp[pos][time]
    dp[pos][time] = 1 << 30
    dp[pos][time] = min(dp[pos][time],
    calc(pos, time + 1),
    calc(pos + 1, time + 1) + abs(a[pos] - time))
    return dp[pos][time]

t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    dp = [[-1 for _ in range(410)] for _ in range(410)]
    print(calc(0, 1))