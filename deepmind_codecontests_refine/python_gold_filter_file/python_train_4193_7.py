t=int(input())
for i in range(t):
	n,m=map(int,input().split())
	a=[]
	for j in range(n):
		a.append(input())
	c=0
	x=a[n-1]
	n1=len(x)
	for j in range(n1-1):
		if(x[j]=='D'):
			c+=1
	y=""
	for j in range(n):
		y=y+a[j][m-1]
	n2=len(y)
	for j in range(n2-1):
		if(y[j]=='R'):
			c+=1
	print(c)