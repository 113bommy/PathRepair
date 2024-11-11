t = int(input())

for i in range(t):

	n = int(input())

	a = [int(i) for i in input().split()]

	s = 0
	xr = 0

	for i in a:
		xr = xr ^ i
		s = s + i

	iin = 55

	A = 1 << iin

	if s % 2 == 1:
		A += 1

	s += A
	xr ^= A

	B = (2 * xr - s) // 2

	print(3)
	print(A, B, B)