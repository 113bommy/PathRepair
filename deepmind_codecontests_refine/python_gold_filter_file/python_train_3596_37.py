n,x=map(int,input().split())
count=0
for i in range(n):
	a,b=map(str,input().split())
	if(a=="+"):
		x=x+int(b)
	elif(a=="-"):
		if(x>=int(b)):
			x=x-int(b)
		else:	
			count=count+1
print(x,count)			
