a_b = list(map(int, input().split(" ")))
a, b = a_b

n = 0
if (a > 1) or (b > 1):
	while (a > 0) and (b > 0):
		if a <= b:
			a += 1
			b -= 2
		else:
			b += 1
			a -= 2
		n += 1
		# print(n, a, b)
print(n)#, a, b)