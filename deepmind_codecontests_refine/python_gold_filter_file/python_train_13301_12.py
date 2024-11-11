r, c, k = map(int, input().split())
v = [map(int, input().split()) for _ in range(k)]

sq = [[0 for _ in range(c)] for _ in range(r)]
for ri, ci, vi in v:
    sq[ri - 1][ci - 1] = vi

dp = [[[0 for _ in range(c)] for _ in range(4)] for _ in range(2)]
for ri in range(r):
    if 0 < ri:
        for ci in range(c):
            dp[ri % 2][0][ci] = max([dp[1 - ri % 2][i][ci] for i in range(4)])
            for i in range(1, 4):
                dp[ri % 2][i][ci] = 0
    for ci in range(c):
        if 0 < ci:
            for i in range(4):
                dp[ri % 2][i][ci] = max(dp[ri % 2][i][ci], dp[ri % 2][i][ci - 1])
        if 0 < sq[ri][ci]:
            for i in range(2, -1, -1):
                dp[ri % 2][i + 1][ci] = max(dp[ri % 2][i + 1][ci], dp[ri % 2][i][ci] + sq[ri][ci])

ans = max([dp[ri % 2][i][-1] for i in range(4)])
print(ans)