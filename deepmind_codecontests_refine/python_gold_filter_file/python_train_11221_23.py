H,N =map(int, input().split())
a = [] 
M = 0 
for i in range(N):
	t = list(map(int, input().split()))
	a.append(t)
	M = max(M,t[0])
dp = [100000000]*(H+1+M)
dp[0] = 0
for i in range(H):
	for j,k in a:
		dp[i+j] = min(dp[i+j],dp[i]+k)

print(min(dp[H:]))