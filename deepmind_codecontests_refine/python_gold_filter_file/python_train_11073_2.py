m = []
n = int(input())
for i in range(1, n + 1):
	m.append(n + 1 - i)
a = list(m)
a.sort()
for i in range(n - 1):
	for j in range(i, n - 1):
		if m[j] > m[j + 1]:
			m[j], m[j + 1] = m[j + 1], m[j]
if m == a:
	print(-1)
else:
	a.reverse()
	print(* a, sep = " ")