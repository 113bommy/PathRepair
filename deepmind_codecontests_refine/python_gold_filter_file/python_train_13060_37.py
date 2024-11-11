a = int(input())
if (a % 2):
	print(9, a - 9)
else:
	if (a % 4):
		print(4, a - 4)
	else:
		print(a // 2, a // 2)