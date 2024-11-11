def countFibs(a,b,n,low, high): 
	x=min(a,b)
	y=(a+b)-x
	f1, f2= y, a+b
	f3=f1+f2
	result = 0

	while (f1 <= high): 
		if (f1 >= low): 
			result += 1
		f1 = f2 
		f2 = f3 
		f3 = f1 + f2 

	return result 

t=int(input())
while(t>0):
	a,b,n=map(int,input().split())
	low, high = 0, n
	print(countFibs(a,b,n,low, high)) 
	t-=1