r, D, x = map(int, input().split())
for j in range(10):
	x = r * x - D
	print(x)
