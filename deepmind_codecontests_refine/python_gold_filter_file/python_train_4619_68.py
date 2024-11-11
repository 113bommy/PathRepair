n = int(input().strip())

c = 0

for i in range(0, n):
	x, y, z = map(int, input().strip().split(' '))

	if (x + y + z) >= 2:
		c += 1

print(c)