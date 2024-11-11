from math import ceil
n,a,b=[int(i)for i in input().split()]
l =  [int(i)for i in input().split()]
d = l[::]
d[0] = 0
d.sort()
for i in range(1,n):
	d[i] += d[i-1]
for i in range(n-1,-1,-1):
 	x = (a* l[0]) / (d[i] + l[0])
 	if x >= b:
 		print(n - 1 - i)
 		exit(0)
