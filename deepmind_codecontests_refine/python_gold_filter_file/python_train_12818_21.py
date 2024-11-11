# import math
# import sys
n,x,y = [int(x) for x in input().strip().split(" ")]
a = [int(x) for x in input().strip().split(" ")]
c = 0
if x>y:
	print(n)
else:
	for i in range(n):
		if a[i]<=x:
			c+=1
	print((c+1)//2)