def sub(x):
	global A;	global F;	global K
	s = 0
	for i in range(N):
		s += max(A[i] - x // F[i], 0)
	return s <= K

N, K = map(int,input().split())
A = list(map(int,input().split())); A.sort()
F = list(map(int,input().split())); F.sort(); F.reverse()
# print(A); print(F)

l = -1; r = max(A) * max(F)
while r - l > 1:
	m = (l + r) // 2
	if sub(m):
		r = m
	else:
		l = m

print(r)