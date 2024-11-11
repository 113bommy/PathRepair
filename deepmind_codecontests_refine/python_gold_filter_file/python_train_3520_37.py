from itertools import accumulate

n = int(input())
aaa = list(map(int, input().split()))
acc = [0] + list(accumulate(aaa))
dp = [[0] * (n + 1) for _ in range(n)]
for l, aa in enumerate(zip(aaa, aaa[1:])):
    dp[l][l + 2] = sum(aa)
for w in range(3, n + 1):
    for l in range(n - w + 1):
        r = l + w
        c = acc[r] - acc[l]
        dp[l][r] = min(dp[l][m] + dp[m][r] + c for m in range(l + 1, r))
print(dp[0][n])
