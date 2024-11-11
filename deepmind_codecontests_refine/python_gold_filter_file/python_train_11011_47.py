import math
N,K = map(int,input().split())
A = list(map(int,input().split()))
for j in range(min(K,int(2*(math.log2(N)))+10)):
	B = [0]*N
	for i in range(N):
		l = max(0,i-A[i])
		r = min(N-1,i+A[i])
		B[l] += 1
		if r < N-1:
			B[r+1] -= 1
	for i in range(1,N):
		B[i] += B[i-1]
	A = B
print(' '.join(map(str,A)))
