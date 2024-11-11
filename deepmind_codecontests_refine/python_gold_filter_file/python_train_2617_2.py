def get(tl, tr, a):
	global A, B
	if len(a) == 0:
		return A
	if tl == tr:
		return len(a) * B
	tm = (tl + tr) // 2
	c, d = [], []
	for x in a:
		if x <= tm:
			c += [x]
		else:
			d += [x]
	return min(B * len(a) * (tr - tl + 1), get(tl, tm, c) + get(tm + 1, tr, d))

n, k, A, B = map(int, input().split())
a = list(sorted(list(map(int, input().split()))))
print(get(1, 1 << n, a))