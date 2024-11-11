while(True):
	a,b=list(map(int,input().split()))
	if a==0 and b==0:
		break
	c=0
	for i in range(1,a+1):
		for j in range(1,i):
			for k in range(1,j):
				if i+j+k==b:
					c+=1
	print(c)