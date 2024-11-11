h, w = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(h)]
b = [list(map(int, input().split())) for _ in range(h)]

x = (h + w) * 80

dp = [[0] * w for _ in range(h)]
d = abs(a[0][0] - b[0][0])
dp[0][0] = 1 << (x - d)

for i in range(h):
    for j, (ae, be) in enumerate(zip(a[i], b[i])):
        if i == j == 0:
            continue

        d = abs(ae - be)
        bt = 0
        if i != 0:
            bt |= dp[i-1][j] << d
            bt |= dp[i-1][j] >> d

        if j != 0:
            bt |= dp[i][j-1] << d
            bt |= dp[i][j-1] >> d

        dp[i][j] = bt

dp = dp[-1][-1]

b = bin(dp)[2:]
can_make = [i - x for i, be in enumerate(b[::-1]) if be == "1"]

ans = min(x if x >= 0 else -x for x in can_make)
print(ans)
