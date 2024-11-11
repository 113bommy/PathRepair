N = int(input())
A = []
for i in range(N):
  As = list(map(int, input().split()))
  A.append(As)
r = 0
for i in range(N):
  for j in range(i+1, N):
    ok = False
    for k in range(N):
      if A[i][j] > A[i][k]+A[k][j]:
        print(-1)
        exit()
      if A[i][j] == A[i][k]+A[k][j] and k != i and k != j:
        ok = True
    if not(ok):
      r += A[i][j]
print(r)
