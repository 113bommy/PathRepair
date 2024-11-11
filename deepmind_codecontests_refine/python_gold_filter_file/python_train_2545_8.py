s=[int(n) for n in input().split()]
x1=s[0]
y1=s[1]
x2=s[2]
y2=s[3]
x3=x4=y3=y4=int()
l=0
if x1==x2 and y1!=y2:
	l=1
elif y1==y2 and x1!=x2:
	l=2
elif abs((y1-y2)/(x1-x2))==1:
	l=3
else:
	l=0
	print(-1)

if l==1:
	p=abs(y1-y2)
	x3=x1+p
	x4=x1+p
	y3=y1
	y4=y2
	print("{} {} {} {}".format(x3,y3,x4,y4))
elif l==2:
	p=abs(x1-x2)
	x3=x1
	x4=x2
	y3=y1+p
	y4=y1+p
	print("{} {} {} {}".format(x3,y3,x4,y4))
elif l==3:
	x3=x1
	y3=y2
	x4=x2
	y4=y1
	print("{} {} {} {}".format(x3,y3,x4,y4))
