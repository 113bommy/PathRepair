for _ in range(int(input())):
	a, b, c = map(int, input().split())
	print(1 if a < c else -1, b if c < a * b else -1)