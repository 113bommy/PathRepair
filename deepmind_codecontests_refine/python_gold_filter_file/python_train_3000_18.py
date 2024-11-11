N, M = map(int, input().split())
listA = list(map(int, input().split()))
c = [0,2,5,5,4,5,6,3,7,6]
dp = [-1]*10010
dp[0] = 0
for j in range(1, N+1):
	for a in listA:
		if j-c[a] >= 0:
			dp[j] = max(dp[j], dp[j-c[a]]*10+a)
print(dp[N])