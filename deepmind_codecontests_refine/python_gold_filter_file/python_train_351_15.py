n = int(input())
a = [int(s) for s in input().split()]

sum, b = 0, 0

for i in a:
	b = max(b, i)
	sum += i

l, r = 1, 2 * b
while l < r:
	m = (l + r) // 2
	if n * m - sum >= m:
		r = m
	else:
		l = m + 1

print(max(l, b))
		