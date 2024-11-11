n = int(input())
ts = [int(c) for c in input().split()]
vs = [int(c) for c in input().split()]

t = sum(ts)
dp = [[-10 ** 10 for _ in range(101)] for _ in range(t + 1)]
dp[0][0] = 0.

mvs = []
for dt, mv in zip(ts, vs):
    for st in range(dt):
        mvs.append(mv)
mvs.append(0)

for ct in range(t):
    mv = mvs[ct]
    for cv in range(mv + 1):
        endmv = min(mv, mvs[ct+1])
        for dv in [-1, 0, 1]:
            nv = cv + dv
            if 0 <= nv <= endmv:
                dp[ct + 1][nv] = max(dp[ct][cv] + (cv + nv) / 2, dp[ct + 1][nv])
        if mv >= cv + 1 and cv <= endmv:
            dp[ct + 1][cv] = max(dp[ct+1][cv], dp[ct][cv] + cv + 0.25)


print(dp[t][0])
