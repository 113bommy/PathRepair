a,b=map(int,input().split())
if a==1 and b==10:
	print(-1)
elif a==1:
	print(b)
else:
	x=10**(a-1)
	print(x+b-x%b)