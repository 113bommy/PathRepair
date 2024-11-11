n,a,b=map(int,input().split())		
f=0
if b<0:
	f=1
	b=b*(-1)
b=b%n
if f==1:
	if a-b<=0:
		print(a+n-b)
	else:
		print(a-b)
else:
	if a+b>n:
		print(a+b-n)
	else:
		print(a+b)		