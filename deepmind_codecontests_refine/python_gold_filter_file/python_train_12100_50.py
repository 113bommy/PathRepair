t=int(input())
for i in range(0,t):
	xyab=list(map(int,input().split()))
	x=xyab[0]
	y=xyab[1]
	a=xyab[2]
	b=xyab[3]
	t=(y-x)/(a+b)
	if(t>0 and int(t)==t):
		print(int(t))
	else:
		print(-1)