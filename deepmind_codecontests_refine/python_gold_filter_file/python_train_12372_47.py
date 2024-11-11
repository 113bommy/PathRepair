N = int(input())
A = [list(map(int, input().split())) for _ in range(N)]

L = []
for i in range(N):
  for j in range(i + 1, N):
    L.append([A[i][j], i, j])

ans = 0
for i in range(N - 1):
  for j in range(i + 1, N):
    for k in range(N):
      if i == k: continue
      if j == k: continue
      if A[i][j] > A[i][k] + A[k][j]:
        print(-1)
        exit()
      if A[i][j] == A[i][k] + A[k][j]:
        break
    else:
      ans += A[i][j]

print(ans)