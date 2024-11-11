a = input()
b = input()

aa = len(a)

bb = len(b)

dp = [[0]*(bb+1) for i in range(aa+1)]

for i in range(aa):
	for j in range(bb):
		if a[i] == b[j]:
			dp[i+1][j+1] = dp[i][j] + 1
		else:
			dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j])

ans = ""

while aa > 0 and bb > 0:
	if a[aa-1] == b[bb-1]:
		aa -= 1
		bb -= 1
		ans += a[aa]
	elif dp[aa][bb-1] > dp[aa-1][bb]:
		bb -= 1
	else:
		aa -= 1
print(ans[::-1])