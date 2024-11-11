n = int(input())
k = input()

dp = [10**18] * len(k) + [0]
st = [100] * len(k) + [-1]

for l in range(len(k) - 1, -1, -1):
	for r in range(l + 1, len(k) + 1):
		if int(k[l:r]) >= n or (k[l] == '0' and r > l+1):
			break
		dp[l], st[l] = min(dp[l], dp[r] + int(k[l:r]) * (n**(st[r]+1))), min(st[l], st[r] + 1)

print(dp[0])