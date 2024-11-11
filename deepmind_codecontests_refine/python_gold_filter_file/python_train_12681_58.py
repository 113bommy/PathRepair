s = input()
t = input()
dp = [[0 for _ in range(len(t)+1)] for _ in range(len(s)+1)]
for i in range(len(s)):
	for j in range(len(t)):
		if s[i] == t[j]:
			dp[i+1][j+1] = dp[i][j] + 1
		elif dp[i+1][j] >= dp[i][j+1]:
			dp[i+1][j+1] = dp[i+1][j]
		else:
			dp[i+1][j+1] = dp[i][j+1]

ans = ""

i, j = len(s), len(t)

while i > 0 and j > 0:
	#if dp[i][j] == dp[i-1][j-1] + 1:
	if s[i-1] == t[j-1]:
		ans += s[i-1]
		i, j = i-1, j-1
	elif dp[i][j-1] >= dp[i-1][j]:
		j -= 1
	else:
		i -= 1

print(ans[::-1])