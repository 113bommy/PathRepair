def points(p, t):
	return max(3 * p // 10, p - p // 250 * t)

a, b, c, d = map(int, input().split())

n = points(a, c)
m = points(b, d)

if n > m:
	print("Misha")
elif m > n:
	print("Vasya")
else:
	print("Tie")
