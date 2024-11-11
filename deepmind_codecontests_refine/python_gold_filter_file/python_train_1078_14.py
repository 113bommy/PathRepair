n = int(input())
if n <= 2:
	print(-1)
elif n==3:
	print(210)
else:
	x = 2*pow(10,n-1,21)%21
	a,b = x//10, x%10

	print("1"+"0"*(n-4)+str(a)+str(b)+"0")