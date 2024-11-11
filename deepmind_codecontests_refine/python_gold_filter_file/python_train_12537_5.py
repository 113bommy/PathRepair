input()
res = r = 0
for i, x in enumerate(input(), 1):
	if x == 'R':
		r = i
	elif x == 'L':
		if r:
			res += (r + i - 1) & 1
		else:
			res = 0
		r = 0
	elif not r:
		res += 1
print(res)