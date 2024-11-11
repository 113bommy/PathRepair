n, k = list(map(int, input().split()))
hs = [0] + list(map(int, input().split())) 


max_val = sum([max(hs[i + 1] - hs[i], 0) for i in range(n)])
dp = [[max_val for _ in range(n + 1)] for _ in range(n + 1)]

dp[0][0] = 0
for i in range(1, n + 1):
	for j in range(1, n + 1):	
		dp[i][j] = min([dp[i - 1][l] + max(hs[j] - hs[l], 0) for l in range(j)])

print(min([dp[n - k][l] for l in range(n + 1)]))