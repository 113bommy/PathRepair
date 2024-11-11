n = int(input())
mat = []
for _ in range(n):
  mat.append(list(map(int,input().split())))

d = [[False]*n for _ in range(n)]

for k in range(n):
  for i in range(n):
    for j in range(n):
      if mat[i][j] > mat[i][k]+mat[k][j]:
        print(-1)
        exit()

      if mat[i][j] == mat[i][k]+mat[k][j] and mat[i][k]>0 and mat[k][j]>0:
        d[i][j] = True

ans = 0
for i in range(n):
  for j in range(i+1, n):
    if not d[i][j]:
      ans += mat[i][j]

print(ans)