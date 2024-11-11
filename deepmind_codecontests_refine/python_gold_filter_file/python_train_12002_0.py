n, m, k = map(int, input().split())
# a = []
# for _ in range(n):
#     a.append(list(map(int, input().split())))
pre = [float("-inf") for i in range(k)]
pre[0] = 0
sz = m // 2
for _ in range(n):
	a = list(map(int, input().split()))
	dp = [[float("-inf") for _ in range(k)] for _ in range(sz + 1)]
	dp[0] = pre
	for x in a:
		for i in range(sz, 0, -1):
			for j in range(k):
				dp[i][j] = max(dp[i][j], dp[i - 1][(j - x) % k] + x)
	for i in range(1, sz + 1):
		for j in range(k):
			dp[0][j] = max(dp[0][j], dp[i][j])
	pre = dp[0]
print(pre[0])