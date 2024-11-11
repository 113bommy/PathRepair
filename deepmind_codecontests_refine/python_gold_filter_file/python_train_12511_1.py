n, k = map(int, input().split())

for i in range(1, n + 1):
	if (1 + i) * i // 2 - (n - i) == k:
		print(n - i)
		break