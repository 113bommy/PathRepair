data = [int(info) for info in input().split(' ')]
a, b, c = data[0], data[1], data[2]
data = [int(info) for info in input().split(' ')]
aa, bb, cc = data[0], data[1], data[2]

if a >= aa and b >= bb and c >= cc:
	print('YES')
elif a < aa and b < bb and c < cc:
	print('NO')
else:
	while (a < aa or b < bb or c < cc) and (a > aa or b > bb or c > cc):
		if a > aa:
			if b < bb:
				a -= 2
				b += 1
			elif c < cc:
				a -= 2
				c += 1
		elif b > bb:
			if a < aa:
				b -= 2
				a += 1
			elif c < cc:
				b -= 2
				c += 1
		elif c > cc:
			if b < bb:
				c -= 2
				b += 1
			elif a < aa:
				c -= 2
				a += 1

	if a >= aa and b >= bb and c >= cc:
		print('YES')
	else:
		print('NO')
