line1 = input().split(' ')
n = int(line1[0])
k = int(line1[1])
s = list(input())

dp = [101*[0] for i in range(101)]
last = 26*[-1]

for i in range(n+1):
    dp[0][i] = 1

for l in range(1, n+1):
    dp[l][0] = 0
    for c in range(26):
        last[c] = -1
    for i in range(1, n+1):
        dp[l][i] = dp[l-1][i-1] + dp[l][i-1]
        if last[ord(s[i-1])-ord('a')] != -1:
            dp[l][i] -= dp[l-1][last[ord(s[i-1])-ord('a')]-1]
        last[ord(s[i-1])-ord('a')] = i

i = 0
res = 0
while i <= n and k >= 0:
    c = min(k, dp[n-i][n])
    k -= c
    res += c * i
    i += 1
if k > 0:
    print(-1)
else:
    print(res)
