# coding=utf-8


if __name__ == '__main__':
	a, b, c = str(input()).split()
	a = int(a)
	b = int(b)
	c = int(c)
	flag = False
	if c > 0:
		if b >= a and (b - a) % c == 0:
			flag = True
	elif c < 0:
		if b <= a and (b - a) % c == 0:
			flag = True
	else:
		if a == b:
			flag = True
	if flag:
		print('YES')
	else:
		print('NO')
