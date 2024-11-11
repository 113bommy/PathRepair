from math import sqrt

a = []
for i in range(11):
	a.append(int(input()))

for x in a[::-1]:
	a = sqrt(abs(x))
	b = 5 * x**3
	if a + b <= 400:
		print("f(%d) = %.2f" % (x, a + b))
	else:
		print("f(%d) = MAGNA NIMIS!" % x)
