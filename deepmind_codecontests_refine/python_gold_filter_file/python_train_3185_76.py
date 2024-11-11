import math
ab=input().split()
a=int(ab[0])
b=int(ab[1])
n=math.log(b/a,1.5)
if(int(n)==n):
	print(int(n)+1)
else:
	print(math.ceil(n))