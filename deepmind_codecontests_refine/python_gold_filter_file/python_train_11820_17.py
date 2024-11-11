input(); t = sorted(set(int(x) for x in input().split()))
for a, b, c in zip(t, t[1:], t[2:]):
	if b - a == c - b == 1:
		print('YES')
		break
else:
	print('NO')
