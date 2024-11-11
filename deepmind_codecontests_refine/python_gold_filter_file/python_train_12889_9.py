n,w = map(int, input().split())
a = [[int(x) for x in input().split()] for i in range(n)]
dp = [10**100 for i in range(10**5 + 1)]
dp[0] = 0
for i in range(n):
    for j in range(10**5, -1, -1):
        if dp[j] != 10**100:
            dp[j + a[i][1]] = min(dp[j + a[i][1]], dp[j] + a[i][0])
for i in range(10**5, -1, -1):
    if dp[i] <= w:
        print(i)
        exit(0)