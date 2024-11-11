from math import ceil
for i in range(int(input())):
	l,r=map(int,input().split())

	if l%2==0 and r%2!=0:
		l=ceil(l/2)
		r=ceil(r/2)
		x1=-1*((r**2))
		x2=(r-1)*r
		y1=(l-1)*l
		y2=-1*(l**2)
	elif l%2!=0 and r%2==0:
		l=ceil(l/2)
		r=ceil(r/2)
		x1=(r*(r+1))
		x2=-1*(r**2)
		y1=-1*((l-1)**2)
		y2=(l-1)*(l)
	elif l%2==0 and r%2==0:
		l=ceil(l/2)
		r=ceil(r/2)
		x1=(r*(r+1))
		x2=-1*(r**2)	
		y1=(l-1)*l
		y2=-1*(l**2)
	else:
		l=ceil(l/2)
		r=ceil(r/2)
		x1=-1*(r**2)
		x2=(r-1)*r
		y1=-1*((l-1)**2)
		y2=(l)*(l-1)
	print(x1+x2-y1-y2)