for t in range(int(input())):
	n=int(input())
	a=list(map(int,input().split()))
	b=[]
	x=[]
	for i in a:
		b.append(i)
	m=min(b)
	c=sorted(a)

	for i in range(n):
		if(b[i]!=c[i]):
			x.append(b[i])	
	#print(x)
	for i in range(len(x)):
		if(x[i]%m !=0):
			print('NO')
			break
	else:	
		print('YES')	