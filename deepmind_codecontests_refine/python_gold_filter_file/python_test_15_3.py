t = int(input())
for _ in range(t):
  n, m, k = map(int, input().split())
  f = []
  for _ in range(n):
    tmp = list(input())
    f.append(tmp)
  #始点を全探索し、塗れたら*を#に置き換え。最後、*が残っちゃうかどうかをチェック

  for i in range(n):
    for j in range(m):
      if f[i][j] == "*" or f[i][j] == "#":
        h = 1
        while i-h >= 0 and j-h >= 0 and j+h < m and (f[i-h][j-h] ==  "*" or f[i-h][j-h] ==  "#") and (f[i-h][j+h] ==  "*" or f[i-h][j+h] ==   "#"):
          h += 1
        h -= 1
        if h >= k:
          for H in range(h+1):
            f[i-H][j-H] = "#"
            f[i-H][j+H] = "#"

  check = 0
  for i in range(n):
    for j in range(m):
      if f[i][j] == "*":
        check = 1

  if check == 0:
    print("YES")
  else:
    print("NO")