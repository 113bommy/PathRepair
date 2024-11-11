n,x,y=map(int,input().split())
a=list(map(int,input().split()))
if x>y:
	print(n)
else:
	c=0
	for i in a:	
		if i<=x:
			c+=1
	print(c-c//2)
