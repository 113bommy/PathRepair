from sys import stdin
n = int(input())
t = stdin.read().splitlines()
a = [list(map(int, i.split())) for i in t]
a.sort(reverse=True, key=lambda k: (k[1], k[0], k[2]))
# print(a)
dp = [[0] * (n + 1) for _ in range(n + 1)]
for i in range(n):
    for l in range(n + 1):
        dp[i + 1][l] = max(dp[i + 1][l], dp[i][l],
                           dp[i][l] + a[i][0] - a[i][1] * a[i][2])
        if l < n:
            dp[i + 1][l + 1] = max(dp[i + 1][l + 1],
                                   dp[i][l] + a[i][0] - a[i][1] * l)
# print(dp)
print(max(dp[n]))
