n = int(input())
s = [['.'] * n for i in range(n)]
print(n * n // 2 + n % 2)
for i in range(n):
	for j in range(n):
		if (i + j) % 2 == 0:
			s[i][j] = 'C'
print('\n'.join([''.join(l) for l in s]))
