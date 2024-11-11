n,k=map(int,input().split())
n,k=n-1,k-1
l=0
r=k
g=k*(k+1)//2
ans=-1
while l<=r:
	m=(l+r)//2
	#print(g,m*(m+1)//2,n,l,r)
	if (g-m*(m+1)//2)>=n:
		ans=k-m
		l=m+1
	else:
		r=m-1
print(ans)
