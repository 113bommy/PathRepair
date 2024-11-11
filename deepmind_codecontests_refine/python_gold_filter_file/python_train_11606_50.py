n = int(input())
a = [1] * n
for i in range(n - 1):
	b = [0] * n
	b[0] = 1
	for j in range(1, n):
		b[j] = b[j - 1] + a[j]
	a = b
print(a[-1])