n, w = map(int, input().split())
wv = [list(map(int, input().split())) for _ in range(n)]

v_total = sum([x[1] for x in wv])
dp = [0] + [float("inf")]*v_total

for i in range(n):
    for j in range(v_total, wv[i][1]-1, -1):
        dp[j] = min(dp[j], dp[j-wv[i][1]]+wv[i][0])

ans = 0
for i in range(v_total+1):
    if dp[i] <= w:
        ans = i
print(ans)