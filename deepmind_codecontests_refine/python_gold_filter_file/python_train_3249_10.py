n = 0
n = int(input())
for kayra in range(0,n):
	x = str(input())
	a = 0
	p = 0
	tmp = x[0]
	b = int(tmp)
	a = len(x) - 1
	#if int(x[0]) == 1 and int(x) < int(x[0] * len(x)):
	#	a -= 1
	p += a * 9
	if int(x) < int(x[0] * len(x)) and int(x[0]) != 1:
		b -= 1
	if int(x[0]) != 1:
		p += b
	if int(x[0]) == 1 and int(x) >= int(x[0] * len(x)):
		p += 1
	if int(x) == 1:
		p = 1
	print(p)
