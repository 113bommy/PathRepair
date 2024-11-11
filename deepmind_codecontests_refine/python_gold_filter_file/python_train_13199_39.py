n=int(input())
ans=n-1
for i in range(2,int(n**(1/2))+1):
	if n%i==0:
		ans=min(ans,i+n//i-2)
print(ans)