N, M = map(int, input().split())
A = [0 for i in range(M)]
B = [0 for i in range(M)]
C = [0 for i in range(M)]
dist = [[float('inf') for j in range(N)] for i in range(N)]
for i in range(M):
	A[i], B[i], C[i] = map(int, input().split())
	dist[A[i]-1][B[i]-1] = C[i]
	dist[B[i]-1][A[i]-1] = C[i]

for k in range(N):
	for i in range(N):
		for j in range(N):
			dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])

count = 0
for i in range(M):
	if dist[A[i]-1][B[i]-1] < C[i]:
		count = count+1

print(count)