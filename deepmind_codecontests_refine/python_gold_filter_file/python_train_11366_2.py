from math import gcd as g
a,b,n=map(int,input().split())
i=1
count=0
while n>0:
	if i%2!=0:
		l=g(a,n)
		count=1
		n-=l
	else:
		l=g(b,n)
		count=0
		n-=l
	i+=1
if count==1:
	print(0)
else:
	print(1)