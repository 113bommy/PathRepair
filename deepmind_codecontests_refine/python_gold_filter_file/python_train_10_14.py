t = int(input())

while t:
	a, b, c = map(int, input().split())

	if c < a:
		print(c)
	else:
		print(b + (c - (b % c)))

	t -= 1

