n, ma, mb = map(int, input().split())
dp = [[[float('inf') for _ in range(401)] for _ in range(401)] for _ in range(n)]
dp[0][0][0] = 0
a0, b0, c0 = map(int, input().split())
dp[0][a0][b0] = c0

for i in range(1, n):
	dp[i][0][0] = 0
	a, b, c = map(int, input().split())
	for j in range(401):
		for k in range(401):
			if j >= a and k >= b:
				dp[i][j][k] = min(dp[i-1][j][k], dp[i-1][j-a][k-b] + c)
			else:
				dp[i][j][k] = dp[i-1][j][k]

ans = float("inf")
cnt = 400 // max(ma, mb)
for i in range(1, cnt + 1):
	ans = min(ans, dp[-1][ma * i][mb * i])

if ans <= 4000:
	print(ans)
else:
	print(-1)