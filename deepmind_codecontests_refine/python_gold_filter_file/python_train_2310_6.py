A = input()

n = len(A)

m = A[0]

print("Mike")

for i in range(1, n):
	if m < A[i]:
		print("Ann")
	else:
		print("Mike")

	m = min(m, A[i])
