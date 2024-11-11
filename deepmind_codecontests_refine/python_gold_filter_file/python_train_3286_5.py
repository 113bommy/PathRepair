from math import sqrt, ceil

def check(x):
	for i in range(2, ceil(sqrt(x)) + 1):
		if x % i == 0:
			return 0
	return 1


n = int(input())
if n <= 3:
	print(1)
elif n % 2 == 0:
	print(2)
elif check(n):
	print(1)
elif check(n - 2):
	print(2)
else:
	print(3)
