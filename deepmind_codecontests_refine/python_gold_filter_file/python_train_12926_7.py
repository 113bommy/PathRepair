[n, k] = [int(i) for i in input().split()]
s = input()
cntsz = [0 for i in range(105)]
dp = [[0 for i in range(105)] for j in range(105)]
lst = [0 for i in range(105)]
prv = [0 for i in range(26)]
n = len(s)
s = '%' + s
for i in range(n + 1):
  dp[i][0]=1
for i in range(1, n + 1):
	lst[i] = prv[ord(s[i])-ord('a')]
	prv[ord(s[i]) - ord('a')] = i
for sz in range(1, n + 1):
	for i in range(1, n + 1):
		dp[i][sz] += dp[i - 1][sz]
		dp[i][sz] += dp[i - 1][sz - 1]
		if lst[i] != 0:
			 dp[i][sz] -= dp[lst[i]-1][sz-1]
for sz in range(1, n + 1):
	for i in range(1, n + 1):
		cntsz[sz] += dp[i][sz]
		cntsz[sz] -= dp[i - 1][sz]
cntsz[0] += 1
done = 0
ans = 0
for i in range(n, -1, -1):
    if done + cntsz[i] >= k:
       ans += (n - i) * (k - done)
       done = k
       break
    done += cntsz[i]
    ans += cntsz[i] * (n - i)
if done < k:
    print(-1)
else:
    print(ans)