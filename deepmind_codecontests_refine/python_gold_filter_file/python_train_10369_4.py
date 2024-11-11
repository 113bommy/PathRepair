x, y, l, r = map(int, input().split())
a = []
for i in range(70):
	for j in range(70):
		cur = x ** i + y ** j
		if cur > r:
			continue
		if cur <= r and cur >= l:
			a.append(cur)
a.sort()
ans = 0
last = l - 1
for it in a:
	ans = max(ans, it - last - 1)
	last = it
ans = max(ans, r - last)
print(ans)

		