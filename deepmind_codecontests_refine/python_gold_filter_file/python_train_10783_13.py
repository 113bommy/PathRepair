n, m = map(int, input().split())

l = 0
r = 2 ** 64

while r - l > 1:
	M = l + r >> 1
	dell = M * (M + 1) // 2 - m * (m + 1) // 2;
	plus = n + max(0, M - m - 1) * m
	if dell >= plus :
		r = M
	else:
		l = M
print(min(r, n))