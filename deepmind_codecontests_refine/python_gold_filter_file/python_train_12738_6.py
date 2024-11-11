n=int(input())
if(n%2==1):
	print(-1)
else:
	arr=[]
	arr.append(2)
	for i in range(1,n):
		if(i%2==0):
			arr.append(i+2)
		else:
			arr.append(i)
	print(*arr)
	