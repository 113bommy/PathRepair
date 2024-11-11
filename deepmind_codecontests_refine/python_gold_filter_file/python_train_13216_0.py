n, u, v, m = map(int, input().split())
usa_mat = [list(map(int, input().split())) for _ in range(n)]
nek_mat = [list(map(int, input().split())) for _ in range(n)]
usa_dic = {}
nek_dic = {}
for y in range(n):
  for x in range(n):
    usa_dic[usa_mat[y][x]] = (x, y)
    nek_dic[nek_mat[y][x]] = (x, y)

usa_count = [0] * (2 * n + 2)
nek_count = [0] * (2 * n + 2)

flag = 0
usa_point = 0
nek_point = 0
for _ in range(m):
  a = int(input())
  if flag:
    continue
  
  if a in usa_dic:
    ux, uy = usa_dic[a]
    usa_count[ux] += 1
    if usa_count[ux] == n:
      usa_point += 1
    usa_count[uy + n] += 1
    if usa_count[uy + n] == n:
      usa_point += 1
    if ux + uy == n - 1:
      usa_count[-1] += 1
      if usa_count[-1] == n:
        usa_point += 1
    if ux == uy:
      usa_count[-2] += 1
      if usa_count[-2] == n:
        usa_point += 1
  
  if a in nek_dic:
    nx, ny = nek_dic[a]
    nek_count[nx] += 1
    if nek_count[nx] == n:
      nek_point += 1
    nek_count[ny + n] += 1
    if nek_count[ny + n] == n:
      nek_point += 1
    if nx + ny == n - 1:
      nek_count[-1] += 1
      if nek_count[-1] == n:
        nek_point += 1
    if nx == ny:
      nek_count[-2] += 1
      if nek_count[-2] == n:
        nek_point += 1
  
  if n == 1:
    usa_point = min(usa_point, 1)
    nek_point = min(nek_point, 1)

  if usa_point >= u and nek_point >= v:
    flag = 1
  elif usa_point >= u:
    flag = 2
  elif nek_point >= v:
    flag = 3

if flag == 2:
  print("USAGI")
elif flag == 3:
  print("NEKO")
else:
  print("DRAW")
