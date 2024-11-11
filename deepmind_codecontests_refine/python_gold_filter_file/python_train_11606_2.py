n = int(input())

a = [[int(i == 0 or j == 0) for j in range(n)] for i in range(n)]

for i in range(1, n):
	for j in range(1, n):
		a[i][j] = a[i - 1][j] + a[i][j - 1]

print(a[n - 1][n - 1])
