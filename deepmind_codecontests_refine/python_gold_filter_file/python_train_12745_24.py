s = input()
a = list(map(int, s.split()))
if a[1] + a[2] > a[0]:
	if a[1] - a[2] <= 1:
		for i in range(1, a[0] + 1):
			if i == a[1] and i != a[1] + a[2] + 1:
				print('(' + str(i) + ')', end=' ')
			elif i == a[1] + a[2] + 1:
				continue
			else:
				print(i, end=' ')
	else:
		print("<<", end=' ')
		for i in range(a[1] - a[2], a[0] + 1):
			if i == a[1] and i != a[1] + a[2] + 1:
				print('(' + str(i) + ')', end=' ')
			else:
				print(i, end=' ')
elif a[1] + a[2] == a[0]:
	if a[1] - a[2] <= 1:
		for i in range(1, a[1] + a[2] + 1):
			if i == a[1] and i != a[1] + a[2] + 1:
				print('(' + str(i) + ')', end=' ')
			elif i == a[1] + a[2] + 1:
				continue
			else:
				print(i, end=' ')
	else:
		print("<<", end=' ')
		for i in range(a[1] - a[2], a[1] + a[2] + 1):
			if i == a[1] and i != a[1] + a[2] + 1:
				print('(' + str(i) + ')', end=' ')
			else:
				print(i, end=' ')
else:
	if a[1] - a[2] <= 1:
		for i in range(1 , a[1] + a[2] + 1):
			if i == a[1] and i != a[1] + a[2] + 1:
				print('(' + str(i) + ')', end=' ')
			elif i == a[1] + a[2] + 1:
				continue
			else:
				print(i, end=' ')
		print(">>", end=' ')
	else:
		print("<<", end=' ')
		for i in range(a[1] - a[2], a[1] + a[2] + 1):
			if i == a[1] and i != a[1] + a[2] + 1:
				print('(' + str(i) + ')', end=' ')
			else:
				print(i, end=' ')
		print(">>", end=' ')