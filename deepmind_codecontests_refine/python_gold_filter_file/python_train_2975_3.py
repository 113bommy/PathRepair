xarr=list()
yarr=list()
xsum=0
ysum=0
for i in range(3):
	x,y=map(int,input().split())
	xarr.append(x)
	yarr.append(y)
	xsum+=x
	ysum+=y
print(3)
for i in range(3):
	print(xsum-2*xarr[i],ysum-2*yarr[i])