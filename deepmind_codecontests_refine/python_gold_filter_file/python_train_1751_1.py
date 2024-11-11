INF = 10**10
n = int(input())
a = list(map(int, input().split()))

dp_fr = [[INF for _ in range(20)] for _ in range(n)]
dp_ba = [[INF for _ in range(20)] for _ in range(n)]

#dp[i][j]: iまで考えてa_iを4^j倍したときの必要最小コスト
for j in range(20):
	dp_fr[0][j] = 2*j

for i in range(1, n):
	if a[i-1] < a[i]:
		k = 0
		while a[i-1] * pow(4, k) < a[i]:
			k += 1
		for j in range(20):
			if j+k < 20:
				dp_fr[i][j] = 2*j + dp_fr[i-1][j+k]
			else:
				dp_fr[i][j] = 2*j + dp_fr[i-1][19] + 2*(i) * (j+k-19)
	else:
		k = 0
		while a[i-1] >= a[i] * pow(4, k+1):
			k += 1
		for j in range(20):
			dp_fr[i][j] = 2*j + dp_fr[i-1][max(j-k, 0)]

for j in range(20):
	dp_ba[n-1][j] = 2*j

for i in range(n-2, -1, -1):
	if a[i+1] < a[i]:
		k = 0
		while a[i+1] * pow(4, k) < a[i]:
			k += 1
		for j in range(20):
			if j+k < 20:
				dp_ba[i][j] = 2*j + dp_ba[i+1][j+k]
			else:
				dp_ba[i][j] = 2*j + dp_ba[i+1][19] + 2*(n-i-1) * (j+k-19)
	else:
		k = 0
		while a[i+1] >= a[i] * pow(4, k+1):
			k += 1
		for j in range(20):
			dp_ba[i][j] = 2*j + dp_ba[i+1][max(j-k, 0)]

#print(*dp_fr, sep="\n")
#print(*dp_ba, sep="\n")

ans = min(dp_ba[0][0], n + dp_fr[n-1][0])
for i in range(n-1):
	ans = min(ans, dp_ba[i+1][0] + i+1 + dp_fr[i][0])

print(ans)