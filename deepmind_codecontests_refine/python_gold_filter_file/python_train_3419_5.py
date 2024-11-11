h,w,d = map(int,input().split())
if d%2:
  for i in range(h):
    for j in range(w):
      if (i+j)%2:
        print("R",end="")
      else:
        print("G",end="")
    print()
else:
  cell = [["A" for i in range(2*d)] for j in range(2*d)]
  for i in range(d):
    for j in range(d):
      if (i+j)%2 == (d//2-1)%2:
        if abs(i-j) <= d//2-1 and d//2-1 <= i+j <= (d//2-1)*3:
          cell[i][j] = "R"
      elif j and cell[i][j-1] == "R":
        cell[i][j] = "R"
  for i in range(2*d):
    for j in range(2*d):
      if cell[(i-d)%(2*d)][(j-d)%(2*d)] == "R":
        cell[i][j] = "R"
      elif cell[(i-d//2)%(2*d)][(j-d//2)%(2*d)] == "R" or cell[(i+d//2)%(2*d)][(j+d//2)%(2*d)] == "R" :
        cell[i][j] = "G"
      elif cell[(i-d)%(2*d)][j] == "R" or cell[i][(j-d)%(2*d)] == "R":
        cell[i][j] = "B"
      elif cell[i][j] == "A":
        cell[i][j] = "Y"
  ans = [["A" for i in range(w)] for j in range(h)]
  for i in range(h):
    for j in range(w):
      x = cell[i%(2*d)][j%(2*d)]
      ans[i][j] = x
    print(*ans[i],sep="")