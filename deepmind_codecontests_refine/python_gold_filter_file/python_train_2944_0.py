import io
import os
import sys
import math

# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')

fileno = sys.stdin.fileno()
input = io.BytesIO(
	os.read(fileno, os.fstat(fileno).st_size)
).readline

T = int(input())
for t in range(T):
	N = int(input())
	A = list(map(int, input().split()))

	F = [None for i in range(N)]
	M = [None for i in range(N)]
	F[0] = A[0]
	M[0] = 1_000_000_000
	if N != 1:
		F[1] = A[0] + A[1]
		M[1] = A[0]
	for i in range(2, N):
		F[i] = min(
			M[i-1] + A[i],
			M[i-2] + A[i-1] + A[i]
		)

		M[i] = min(F[i-1], F[i-2])
	# print(A)
	# print(F)
	# print(M)
	print(min(F[N-1], M[N-1]))

