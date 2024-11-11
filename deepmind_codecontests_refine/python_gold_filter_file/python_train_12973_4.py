n=int(input())
from math import sqrt
k=int(sqrt(n))
if k==sqrt(n):
	print(4*k)
else:
	if n<=k*(k+1):
		print(2*(2*k+1))
	else:
		print(4*(k+1))