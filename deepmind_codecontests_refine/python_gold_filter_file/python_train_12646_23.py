input()
s = input().lower()

if len(sorted(list(set(s)))) == 26:
	print('YES')
else:
	print('NO')