t = 0
while t == 0:	
	try:
		x,y=[int(i) for i in input().split()]
	except:
		break
	else:
		a = x * y
		if x < y:
			x,y =y,x
		while y > 0:
			r = x % y
			x = y
			y = r
	print(str(x) + " " + str(int(a / x)))