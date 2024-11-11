n,b = int(input()),1
while True:
	a = n+b

	while a:
		if abs(a) % 10 == 8:
			print(b)
			exit()
		if a > 0:
			a//=10
		else:
			a = - (abs(a) // 10)
	b+=1