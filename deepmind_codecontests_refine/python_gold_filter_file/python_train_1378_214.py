for _ in range(int(input())):
	x = int(input())
	print(x - 1, 1) if x & 1 else print(x //2, x // 2)