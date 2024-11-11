n, v = [int(x) for x in input().split()]
l = [0] * 3002
for i in range(n):
	a, b = [int(x) for x in input().split()]
	l[a] += b
ans = 0
for i in range(1, 3002):
	left = v
	if l[i - 1]:
		ans += min(left, l[i - 1])
		left -= min(left, l[i - 1])
	ans += min(left, l[i])
	l[i] -= min(left, l[i])
print(ans)
