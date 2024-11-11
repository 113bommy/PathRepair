import math

n = int(input())
a = list(map(int, input().split()))

z2 = a.count(0)
o2 = n - z2
z1 = 0
o1 = 0

res = z1 + o2
i = 0
while i < n:
	z2 -= (1-a[i])
	z1 += (1-a[i])
	o2 -= (a[i])
	o1 += (a[i])
	res = max(res, z1+o2)
	i+=1
print(res)