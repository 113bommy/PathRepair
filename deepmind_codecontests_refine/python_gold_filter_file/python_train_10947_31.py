q = int(input())
for i in range(q):
	x = int(input())
	flag = 1
	kol = 0
	while x > 1 and flag:
		flag = 0
		if x % 2 == 0:
			kol += 1
			x //= 2
			flag = 1
	flag = 1
	while x > 1 and flag:
		flag = 0
		if x % 3 == 0:
			kol += 2
			x //= 3
			flag = 1
	flag = 1
	while x > 1 and flag:
		flag = 0
		if x % 5 == 0:
			kol += 3
			x //= 5
			flag = 1
	if x > 1:
		print (-1)
	else:
		print (kol)
