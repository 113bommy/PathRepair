n=int(input())
a=list(map(int,input().split()))
M=10**9+7
dp=[0 for i in range(10**6+1)]
ans=0
for i in range(n):
	temp=[]
	for j in range(1,int(a[i]**0.5)+1):
		if(a[i]%j==0):
			f1=j
			f2=a[i]//j
			if(f1==f2):
				if(f1==1):
					ans+=1
					ans%=M
					temp.append([1,dp[1]+1])
				else:
					ans+=dp[f1-1]
					ans%=M
					temp.append([f1,dp[f1]+dp[f1-1]])
			else:
				if(f1==1):
					ans+=1
					ans%=M
					temp.append([1,dp[1]+1])
				else:
					ans+=dp[f1-1]
					ans%=M
					temp.append([f1,dp[f1]+dp[f1-1]])
				if(f2==1):
					ans+=1
					ans%=M
					temp.append([1,dp[1]+1])
				else:
					ans+=dp[f2-1]
					ans%=M
					temp.append([f2,dp[f2]+dp[f2-1]])
	for j in range(len(temp)):
		dp[temp[j][0]]=temp[j][1]
print(ans)            