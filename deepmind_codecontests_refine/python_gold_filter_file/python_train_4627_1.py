n,m=map(int,input().split())
a=list(map(int,input().split()))
ans=m
mx=a[-1]
for i in range(n-2,-1,-1):
	mx=max(mx,a[i])
	ans=max(ans,m//a[i]*mx+m%a[i])
print(ans)
