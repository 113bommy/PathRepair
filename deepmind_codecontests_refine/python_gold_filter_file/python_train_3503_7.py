n, k, A, B = int(input()), int(input()), int(input()), int(input())
if k == 1:
	print((n - 1) * A)
else:
	ans = (n - 1) * A
	for i in range(1, 64):
		pw = k ** i
		if pw > n:
			break
		cur_ans, x = i * B, n - pw
		while pw > 0:
			cur_ans += A * (x // pw)
			x %= pw
			pw //= k
		ans = min(ans, cur_ans)
	print(ans)