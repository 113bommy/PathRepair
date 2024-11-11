from math import ceil

k = int(input())

for i in range(k):
	n = int(input())
	if n==2:
		print(2)
	else:
		a = ceil(n/2)
		print(a-n//2)