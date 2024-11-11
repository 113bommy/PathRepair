n, m, h = map(int,input().split())
s = 0
for i in range(1, h + 1):
	a = n - 4 * (i - 1)
	b = m - 4 * (i - 1)
	s += 2 * (a + b) - 4
print(s)
