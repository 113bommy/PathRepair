c,v0,v1,a,l=map(int,input().split())
r=v0
ans=1
while r<c:
	v0=min(v1,v0+a)
	r=min(r-l+v0,c)
	ans+=1
print (ans)
