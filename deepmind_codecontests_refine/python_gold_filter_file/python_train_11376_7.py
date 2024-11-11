t = int(input())
for i in range(t):
	n, l = map(int, input().split())
	a = list(map(int, input().split()))
	tmp1 = 0
	tmp2 = n - 1
	t = 0
	v1 = 1
	v2 = 1
	x1 = 0
	x2 = l
	while (tmp2 - tmp1) > -1:
		t1 = (a[tmp1] - x1) / v1
		t2 = (x2 - a[tmp2]) / v2
		if t1 > t2:
			x1 += v1 * t2
			x2 -= v2 * t2
			v2 += 1
			t += t2
			tmp2 -= 1
		elif abs(t1 - t2) < 0.000000001:
			x1 += v1 * t1
			x2 -= v2 * t2
			v1 += 1
			v2 += 1
			t += t1
			tmp2 -= 1
			tmp1 += 1
		else:
			x1 += v1 * t1
			x2 -= v2 * t1
			v1 += 1
			t += t1
			tmp1 += 1
	t += (x2 - x1) / (v1 + v2)
	print("{:.07f}".format(t))
		
