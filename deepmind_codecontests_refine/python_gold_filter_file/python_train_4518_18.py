from math import *
a,b,n=map(int,input().split())
if a*b<0 and n%2==0:
	print('No solution')
elif a==0 and b!=0:
	print('No solution')
elif a==0 and b==0:
	print(0)
else:
	j=abs(b/a)**(1/n)
	if a*b<0:
		j=-j
	if a*ceil(j)**n==b:
		print(ceil(j))
	elif a*floor(j)**n==b:
		print(floor(j))
	else:
		print('No solution')