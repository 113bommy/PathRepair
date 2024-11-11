def gcd(a, b):
	while a:
		b %= a
		a, b = b, a
	return b

def lcm(a, b):
	return a // gcd(a, b) * b

n = int(input())
ans = 0
for i in range(n, max(0, n - 100), -1):
	for j in range(i, max(0, i - 100), -1):
		cur = lcm(i, j)
		for k in range(j, max(0, j - 100), -1):
			ans = max(ans, lcm(cur, k))
print(ans)
