n,x,m=map(int,input().split())
i=int(2)
a=[x]
q=int(0)
while (i <= n) and (q == 0):
	x=(x**2)%m
	if x in a:
		q=1
	else:
		a.append(x)
	i=i+1

if len(a) == n:
	print(sum(a))	
else:
	j=a.index(x)
	b=a[0:j]
	c=a[j:]
	lb=len(b)
	lc=len(c)
	k=(n-lb)%lc
	l=(n-lb)//lc
	d=c[0:k]
	print(sum(b)+sum(c)*l+sum(d))