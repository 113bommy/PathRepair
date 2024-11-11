c = []
for _ in [0]*3:
  c += [list(map(int, input().split()))]

flag = True
for i in [0,1]:
  for j in [0,1]:
    if c[i][j] + c[i+1][j+1] != c[i+1][j] + c[i][j+1]:
      flag = False
print("Yes" if flag else "No")