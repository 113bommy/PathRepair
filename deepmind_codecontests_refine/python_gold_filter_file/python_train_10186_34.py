from itertools import permutations

N, M, R = map(int, input().split())
r = list(map(int, input().split()))
for i in range(R):
  r[i] -= 1

d = [[10000000000]*N for _ in range(N)]
for i in range(N):
  d[i][i] = 0

for i in range(M):
  A, B, C = map(int, input().split())
  d[A-1][B-1] = C
  d[B-1][A-1] = C
  
for k in range(N):
  for i in range(N):
    for j in range(N):
      d[i][j] = min(d[i][j], d[i][k]+d[k][j])
      
perms = permutations(r, R)
ans = 10000000000
for perm in perms:
  now = 0
  for i in range(R-1):
    now += d[perm[i]][perm[i+1]]
  ans = min(ans, now)
  
print(ans)
