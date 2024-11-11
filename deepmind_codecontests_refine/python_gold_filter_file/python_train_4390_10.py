def dl(x):
	d = 2
	new = []
	while d * d < x:
		if x % d == 0:
			new.append(d)
			new.append(x // d)
		d += 1
	if d * d == x:
		new.append(d)
	return new


t = int(input())
for i in range(t):
	n = int(input())
	sp = list(map(int, input().split()))
	sp.sort()
	ch = sp[0] * sp[-1]
	new = dl(ch)
	new.sort()
	if sp == new:
		print(ch)
	else:
		print(-1)
