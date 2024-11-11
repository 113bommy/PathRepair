import sys

n = int(sys.stdin.readline().rstrip())
a = [0] * 1000040
dp = [0] * 1000040

for i in range(0, n):
    pos = 0
    r = 0
    temp = sys.stdin.readline().rstrip()
    temp2 = temp.split(" ")
    a[int(temp2[0])] = int(temp2[1])

f = 0
posf = 0
for i in range(0, 1000001):
	if a[i] == 0:
		dp[i] = dp[i - 1]
	else:
		if f == 0:
			dp[i] = 1
			f += 1
			posf = i
		elif i - posf <= a[i]:
			dp[i] = 1
		else:
			dp[i] = dp[i - a[i] - 1] + 1
ans = 0
for i in range(0, 1000001):
    ans = max(ans, dp[i])

print(n - ans)
