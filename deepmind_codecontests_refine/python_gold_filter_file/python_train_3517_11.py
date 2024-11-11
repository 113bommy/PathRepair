N, M, K = map(int, input().split())

parents = [-1] * N
friend = [set() for _ in range(N)]

def find(x):
	if parents[x] < 0:
		return x
	else:
		parents[x] = find(parents[x])
		return parents[x]

def union(x, y):
	x = find(x)
	y = find(y)

	if x == y:
		return

	if parents[x] > parents[y]:
		x, y = y, x

	parents[x] += parents[y]
	parents[y] = x

for _ in range(M):
	A, B = map(int, input().split())
	union(A-1, B-1)
	friend[A-1].add(B-1)
	friend[B-1].add(A-1)

a = [-parents[find(i)]-len(friend[i])-1 for i in range(N)]

for _ in range(K):
	C, D = map(int, input().split())
	if find(C-1) == find(D-1):
		a[C-1] -= 1
		a[D-1] -= 1
print(*a)
