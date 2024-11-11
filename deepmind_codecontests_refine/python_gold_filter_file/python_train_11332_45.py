n,m=map(int,input().split())
l=[input() for i in range(n)]
ml=[input() for i in range(m)]
for i in range(n-m+1):
  for j in range(n-m+1):
    for h in range(m):
      if ml[h]!=l[i+h][j:j+m]:break
    else:print("Yes");exit()
print("No")