n=int(input())
a=list(input())
for i in range(n):
	a[i]=int(a[i])
c=0	
s=0
for i in range(0,n):
	s=sum(a[:i+1])
	d=i+1
	c=0
	su=0
	while(d<n and su<=s):
		su+=a[d]
		d+=1
		if (su==s):
			su=0
			c+=1	
	if d>=n and c>0 and su==0:
		print("YES")
		exit()		
print("NO")

