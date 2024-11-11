n,k=map(int,input().split())
h=list(map(int,input().split()))
dp=[0]
for i in range(1,n):
	p=10**12
	for j in range(k):
		if j>=i:
			break
		else:
			p=min(p,dp[i-j-1]+abs(h[i]-h[i-j-1]))
	dp.append(p)
print(dp[-1])