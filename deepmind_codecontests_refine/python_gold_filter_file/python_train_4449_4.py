def calc(x, h):
	if x <= h:
		return x * (x + 1) // 2
	p = (x - h + 1) // 2
	return ((2 * h + p - 1) * p) // 2 + (x - p) * (x - p + 1) // 2

n, h = map(int, input().split())

ok = 10000000000
ng = 0
while ok - ng > 1:
	m = (ok + ng) // 2
	if calc(m, h) >= n:
		ok = m
	else:
		ng = m
print(ok)