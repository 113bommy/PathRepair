N, M, L = map(int, input().split())
D = [[1000000000000]*N for i in range(N)]
for i in range(N):
  D[i][i] = 0
for i in range(M):
  A, B, C = map(int, input().split())
  A, B = A-1, B-1
  D[A][B] = C
  D[B][A] = C
for k in range(N):
  for i in range(N):
    for j in range(N):
      D[i][j] = min(D[i][j], D[i][k]+D[k][j])
E = [[1000000000000]*N for i in range(N)]
for i in range(N):
  E[i][i] = 0
for i in range(N):
  for j in range(N):
    if D[i][j] <= L:
      E[i][j] = 1
for k in range(N):
  for i in range(N):
    for j in range(N):
      E[i][j] = min(E[i][j], E[i][k]+E[k][j])
Q = int(input())
for i in range(Q):
  s, t = map(int, input().split())
  s, t = s-1, t-1
  if E[s][t] == 1000000000000:
    r = -1
  else:
    r = E[s][t]-1
  print(r)
