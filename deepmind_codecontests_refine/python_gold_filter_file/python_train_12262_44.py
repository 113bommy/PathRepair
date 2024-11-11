k=int(input())
z=range(1,k+1)
import math
from functools import reduce
sum=0
for i in z:
	for j in z:
		for jj in z:
			sum=sum+reduce(math.gcd,[i,j,jj])
print(sum)