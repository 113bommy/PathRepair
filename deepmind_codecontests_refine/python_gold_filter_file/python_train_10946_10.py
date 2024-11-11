f = [0, 1, 2, 0, 2, 1, 0]
def calc(a, i):
	res = 0
	while True:
		if a[f[i]] == 0:
			break
		a[f[i]] -= 1
		res += 1
		i += 1
		i %= 7
	return res
a = list(map(int, input().split()))
x = min(a[0] // 3, a[1] // 2, a[2] // 2)
print(x * 7 + max(calc([a[0] - x * 3, a[1] - x * 2, a[2] - x * 2], i) for i in range(7)))