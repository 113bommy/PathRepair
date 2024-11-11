v=[-1,2,5,5,4,5,6,3,7,6]

N,M=map(int, input().split())
A=sorted(map(int, input().split()), reverse=True)

dp=[0]*(N+999)
mp=[[] for _ in range(N+999)]

for a in reversed(A):
	dp[v[a]] = 1
	mp[v[a]] = [a]

for i in range(N+1):
	for a in A:
		if i-v[a] >= 0 and dp[i-v[a]] > 0 and dp[i] < 1 + dp[i-v[a]]:
			dp[i] = 1 + dp[i-v[a]]
			mp[i] = [a] + mp[i-v[a]]

print("".join(map(str, mp[N])))
