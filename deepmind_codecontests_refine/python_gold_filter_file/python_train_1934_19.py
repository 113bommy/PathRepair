n = int(input())

if n % 2 == 0:
	print(n // 2)
	for i in range(n // 2): print(2)
else:
	print((n - 3) // 2 + 1)
	for i in range((n - 3) // 2): print(2)
	print(3)