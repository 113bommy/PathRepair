l, r, k = map(int, input().split())
if k == 1:
	if 1 <= r and 1 >= l:
		print(1)
else:
	a = 1
	f = 0
	while a <= r:
		if a >= l:
			print(a, end=" ")
			f = 1
		a *= k
	if not f:
		print(-1)