a1, a2 = map(int, input().split())

if a1 + a2 - 2:
	if (a1 - a2) % 3 == 0:
		print(a1 + a2 - 3)
	else:
		print(a1 + a2 - 2)
else:
	print(0)