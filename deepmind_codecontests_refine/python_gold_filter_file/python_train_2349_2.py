a, b = map(int, input().split())
cnt = 1
op = [b]
while b > a:
	if b % 10 == 1:
		b //= 10
		cnt += 1
		op.append(b)
	elif b % 10 % 2 == 0:
		b //= 2
		cnt += 1
		op.append(b)
	else:
		print('NO')
		exit()
if b < a:
	print('NO')
else:
	print('YES')
	print(cnt)
	print(' '.join(map(str, op[::-1])))