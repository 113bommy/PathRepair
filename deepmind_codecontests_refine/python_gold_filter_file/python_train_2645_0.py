def reduce(a, b):
	if (a == 1 or b == 1):
		return max(a, b)
	else:
		a, b = b, a
		return a // b + reduce(a % b, b)

a, b = map(int, input().strip().split())

ans = a // b
a %= b
if (a != 0):
	ans += reduce(a, b)
print(ans)