from math import pi
n = int(input())
a = sorted(list(map(int, input().split())))
area = 0
for i in range(n):
	if i % 2 == 0:
		area += pi * a[i] * a[i]
	else:
		area -= pi * a[i] * a[i]
print(abs(area))
