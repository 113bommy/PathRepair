w,m,k=map(int, input().split())
z=m
dig=0
while z>0:
	dig+=1;
	z=z//10
if(dig*k>w):
	print(0)
	exit(0)
lo=m-1
hi=w+m+5
while lo+1<hi:
	mid=(lo+hi)//2
	cost, t, d=0,0,0
	x=mid
	while x>0:
		x=x//10
		d+=1
	if(d==dig):
		cost=(mid-m+1)*d*k
	else:
		t=pow(10, dig)
		last=m
		c=dig
		while t<=mid:
			cost+=(t-last)*c*k
			c+=1
			last=t
			t=t*10
		t=t//10
		cost+=(mid-t+1)*c*k
	if(cost<=w):
		lo=mid
	else:
		hi=mid
print(lo-m+1)
