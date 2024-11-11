n=int(input())
l=list(map(int,input().split()))
ans=0
for i in range(n):
	dp=l[::]
	count=dp[i]
	for j in range(i+1,n):
		dp[j]=min(dp[j-1],dp[j])
		count+=dp[j]
	for j in range(i-1,-1,-1):
		dp[j]=min(dp[j+1],dp[j])
		count+=dp[j]
	# print (dp)
	if count>ans:
		ans=count
		al=dp[::]
print (*al)