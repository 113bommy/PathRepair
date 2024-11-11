from itertools import permutations
n,m,r = map(int,input().split())
rl = list(map(int,input().split()))
d = [[10**8]*n for i in range(n)]
for i in range(m):
  a,b,c = map(int,input().split())
  d[a-1][b-1] = d[b-1][a-1] = c
for k in range(n):
  for i in range(n):
    for j in range(n):
      d[i][j] = min(d[i][j],d[i][k]+d[k][j])
m = 10**9
for i in permutations(rl):
  c = 0
  for j in range(1,r):
    c += d[i[j-1]-1][i[j]-1]
  m = min(m,c)
print(m)