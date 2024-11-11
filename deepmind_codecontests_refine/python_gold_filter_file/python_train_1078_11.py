
n = int(input())

s = 10 ** (n - 1)

while s % 21 != 0:
	s += 10

if n > 2:
	print(s)
else:
	print(-1)
