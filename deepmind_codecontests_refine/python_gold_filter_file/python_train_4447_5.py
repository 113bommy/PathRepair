def f(N, H, n):
	total = 0
	if n <= H:
		total = n * (n + 1) // 2
	else:
		total = H * (H + 1) // 2
		n -= H
		n -= 1
		total += H
		q, r = n // 2, n % 2
		total += (q * (q + 1) // 2 + q * H) * 2
		total += r * (H + q + 1)
	return total >= N

n, H = map(int, input().split())
l = 0
r = n
while l < r:
	m = (l + r) // 2
	if f(n, H, m):
		r = m
	else:
		l = m + 1
print(r)