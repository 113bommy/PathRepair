a,b,c=map(int,input().split())
if abs(a-b)>1:
	print(a+b+2*c-abs(a-b)+1)
else:
	print(a+b+2*c)