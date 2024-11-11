while True:
	x,y=map(int,input().split())
	if (x==0) & (y==0):
		break
	else:
		if x>y:
			print(y,x)
		else:
			print(x,y)