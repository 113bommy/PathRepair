# your code goes here
t=int(input())
for i in range(t):
	x,y,n=map(int,input().split())
	if x>n:
		print(y)
	elif x+y==n:
		print(n)
	else:
		a=(n//x)
		while a>=0:
			n1=(a*x)+y
			if n1<=n:
				print(n1)
				break
			else:
				a-=1