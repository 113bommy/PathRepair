#In the name of GOD!

def chk(x):
	for a in range(x):
		for b in range(x):
			a = a + 1
			b = b + 1
			if a % b == 0 and a * b > x and a / b < x:
				print(str(a) + str(' ') + str(b))
				return True

x = int(input())
if not chk(x):
	print(-1)
