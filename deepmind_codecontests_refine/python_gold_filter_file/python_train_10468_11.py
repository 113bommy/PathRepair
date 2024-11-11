a = list(input())

x, y = ord(a[0]) - ord('a') + 1, int(a[1])

if x == 1 or x == 8:
	if 1 < y < 8:
		res = 5
	else:
		res = 3
elif y == 1 or y == 8:
	if 1 < x < 8:
		res = 5
	else:
		res = 3
else:
	res = 8
print(res)
