import itertools
n, m, R = map(int, input().split())
r = list(map(int, input().split()))

d = [[10**7 for j in range(n)] for i in range(n)]
for i in range(m):
  a, b, c = map(int, input().split())
  a -= 1
  b -= 1
  d[a][b] = c
  d[b][a] = c

for i in range(n):
  d[i][i] = 0

for k in range(n):
  for i in range(n):
    for j in range(n):
      d[i][j] = min(d[i][k]+d[k][j],d[i][j])

# print (d)
ans = 10**8
for i in itertools.permutations(r):
  x = i
  k = 0
  for j in range(R-1):
    a,b = x[j+1],x[j]
    a -= 1
    b -= 1
    k += d[b][a]
  ans = min(ans,k)
print (ans)