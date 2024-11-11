n=int(input())
a=list(map(int,input().split()))
ans=-10**9-1
mini=0
temp=0
for i in range(n-1):
	if(i%2==0):temp+=abs(a[i]-a[i+1])
	else:temp-=abs(a[i]-a[i+1])
	mini=min(mini,temp)
	ans=max(ans,temp-mini)
mini=0
temp=0
for i in range(1,n-1):
	if(i%2==0):temp-=abs(a[i]-a[i+1])
	else:temp+=abs(a[i]-a[i+1])
	mini=min(mini,temp)
	ans=max(ans,temp-mini)	
print(ans)