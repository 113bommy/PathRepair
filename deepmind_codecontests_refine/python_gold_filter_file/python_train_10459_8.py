import math
a,b=map(int,input().split())
l=[]
if(b==a):
	print("infinity")
elif(b>a):
	print(0)

else:
	
	count=0
	n=a-b
	n1=n
	n=n+1
	n=int(math.sqrt(n))
	#print(n)
	for i in range(1,n+1):
		if(n1%i==0):
			x=n1//i
			if(i>b):
				l.append(i)
			if(x>b):
				l.append(x)

	
	print(len(set(l)))
	#print(l)
	