n=int(input())
a=list(map(int,input().split()))
if n<=2:
	print(n)
	exit()
dp=[0]*n
dp[0]=1
dp[1]=2
for i in range(2,n):
	if a[i]==(a[i-1]+a[i-2]):
		dp[i]=dp[i-1]+1
	elif dp[i-1]==1:
		dp[i]=2
	elif dp[i-1]>=2:
		dp[i]=2
	else:
		dp[i]=1
print(max(dp))
