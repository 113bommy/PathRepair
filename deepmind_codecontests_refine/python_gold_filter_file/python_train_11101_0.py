B = [1, 0]  # 1x + 0
R = [1]  # 0x + 1
A = list(B)

n = int(input())

for i in range(1, n):
	A += [0]
	# print('A =', A)
	# print('R =', R)
	# print('B =', B)
	
	for j in range(-1, -len(R)-1, -1):
		A[len(A)+j] += R[len(R)+j]

		if A[len(A)+j] == 2:
			A[len(A)+j] = 0

	R = list(B)
	B = list(A)
	# print(i, A, R)

print(len(B)-1)
for u in reversed(B):
	print(u, end=' ')
print()

print(len(R)-1)
for u in reversed(R):
	print(u, end=' ')
print()
