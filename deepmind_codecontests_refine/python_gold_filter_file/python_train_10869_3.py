n = int(input())
A = list(map(int, input().split()))
cnt = 1000000000
l, r = 0, 0
for i in range(1, n):
	if abs(A[i] - A[i - 1]) < cnt:
		cnt = abs(A[i] - A[i - 1])
		l = i
		r = i + 1
if abs(A[n - 1] - A[0]) < cnt:
	l, r = 1, n
print(l, r)
