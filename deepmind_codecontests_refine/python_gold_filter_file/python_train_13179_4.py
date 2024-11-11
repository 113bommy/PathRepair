a=int(input())
b=[]
for i in range(a):
  b.append([int(x) for x in input().split()])
for i in range(a):
  for j in range(a):
    if b[i][j]==1:
      continue
    y=1
    for h in range(a):
      for g in range(a):
        if b[i][h]+b[g][j]==b[i][j]:
          y=2
    if y==1:
      print("NO")
      exit()
print("YES")
      
      