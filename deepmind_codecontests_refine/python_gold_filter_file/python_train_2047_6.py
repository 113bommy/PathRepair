n, m, k = map(int, input().split())
if k < n:
	print(k + 1, 1)
elif k < n + m - 1:
	print(n, k - n + 2)
else:
	r = (k - (n + m - 1)) // (m - 1)
	if (r & 1) == 0:
		c = m - (k - (n + m - 1)) % (m - 1)
	else:
		c = 2 + (k - (n + m - 1)) % (m - 1)
	print(n - 1 - r, c)