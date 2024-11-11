n = int(input())
L = [input() for i in range(n)]
for line in L:
	A = line.split()
	B = sorted([int(A[i]) for i in range(3)])
	if B[2]**2 == B[0]**2 + B[1]**2:
		print('YES')
	else:
		print('NO')