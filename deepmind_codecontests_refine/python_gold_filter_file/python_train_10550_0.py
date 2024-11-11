import math
n=int(input())
flag=False
x=int(math.sqrt(2*n))
flag=False
for i in range(1,x+1):
	a=2*n-(i*(i+1))
	if a>0:
		b=math.sqrt(1+4*a)
		if (b-1)/2==int((b-1)/2):
			flag=True
			print('YES')
	if flag==True:
		break
if flag==False:
	print('NO')
