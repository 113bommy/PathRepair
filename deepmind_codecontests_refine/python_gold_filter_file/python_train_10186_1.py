from itertools import permutations

N, M, R = [int(n) for n in input().split()]
r = [int(n)-1 for n in input().split()]
d = [[100000000]*N for n in range(N)]

for i in range(N):
  d[i][i] = 0

for m in range(M):
  A, B, C = [int(n) for n in input().split()]
  A-=1
  B-=1
  d[A][B] = C
  d[B][A] = C

for k in range(N):
  for i in range(N):
    for j in range(N):
      d[i][j] = min(d[i][k]+d[k][j], d[i][j])

res = 1000000000
for perm in permutations(range(R)):
  s = 0
  for i in range(R-1):
    s += d[r[perm[i]]][r[perm[i+1]]]
  res = min(s, res)

print(res)