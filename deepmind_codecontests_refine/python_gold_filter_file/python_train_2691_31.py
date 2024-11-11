n,a,b,*H=map(int,open(0).read().split())
l,r=0,10**9
while r-l>1:
	x=0
	m=(l+r)//2
	s=m*b
	for h in H:
		x-=min(0,(h-s)//-(a-b))
	if x>m:
		l=m
	else:
		r=m
print(r)