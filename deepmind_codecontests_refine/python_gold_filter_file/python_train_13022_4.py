n,m=map(int,input().split())
a=[]
for i in range(n):
  l,r=map(int,input().split())
  for j in range(l,r+1):
    if j not in a:
      a.append(j)
k=[]
i=0
for i in range(1,m+1):
  if i not in a:
    k.append(i)
if len(k)==0:
  print("0")
else:
  print(len(k))
  print(*k)