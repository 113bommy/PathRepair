n, H = map(int, input().split())

mx = int((1 + 8 * n) ** 0.5)
while (mx + 1) * (mx + 1) <= 1 + 8 * n:
	mx += 1
mx = (mx - 1) // 2;

if mx <= H:
	if (1 + mx) * mx // 2 < n:
		mx += 1
	print(mx)
	exit()
else:
	mx = H
	n -= (1 + H) * H // 2

def f(moves, mx):
	res = moves * mx
	add = (moves - 1) // 2
	res += (add + 1) * add
	if moves % 2 == 0:
		res += add + 1
	return res


l = 1
r = 10 ** 18

while l < r - 1:
	m = (l + r) // 2
	if f(m, mx) < n:
		l = m
	else:
		r = m

if f(l, mx) >= n:
	r = l

print(mx + r)