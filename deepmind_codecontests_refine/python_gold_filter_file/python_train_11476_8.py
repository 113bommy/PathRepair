import math
n,m=map(int,input().split())
arr=list(map(int,input().split()))
if n>m:
	print(0)
else:
	ans=1
	for i in range(n):
		for j in range(i+1,n):
			temp=abs(arr[i]-arr[j])%m 
			ans=(ans*temp)%m 
	print(ans)