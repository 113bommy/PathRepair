r, g, b = (int(x) for x in input().split())
res = 0
if r > 3:
	res += (r - 3) // 3
	r -= (r - 3) // 3 * 3
if g > 3:
	res += (g - 3) // 3
	g -= (g - 3) // 3 * 3
if b > 3:
	res += (b - 3) // 3
	b -= (b - 3) // 3 * 3
tot = 0
for i in range(2 ** 3):
	cur = 0
	left = 100
	l = [r, g, b]
	for j in range(3):
		if (2 ** j) & i:
			if l[j] >= 3:
				cur += 1
				l[j] -= 3
		left = min(left, l[j])
	tot = max(tot, res + cur + left)
print(tot)
