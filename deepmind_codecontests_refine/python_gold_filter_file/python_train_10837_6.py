s, a = input(), 0
for i in range(5, 0, -1):
	if len(s) // i + (len(s) % i != 0) < 21:
		a = i;
x, y, b = len(s) % a, 0, len(s) // a
print(a, b + (x != 0))
for i in range(a):
	print(s[b * i + y : b * i + y + b + (x != 0)], end = '')
	print('' if x != 0 else '*' * (len(s) % a != 0))
	if x != 0:
		x -= 1
		y += 1