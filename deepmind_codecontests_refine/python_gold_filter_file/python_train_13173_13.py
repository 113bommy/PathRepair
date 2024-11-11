n,d=map(int,input().split())
l=[]
l1=[]
for i in range(d):
  s=input()
  l.append(s)
c=0
for i in range(d):
  for j in range(n):
    if l[i][j]=='0':
      c+=1
      break
  else:
    l1.append(c)
    c=0
if l1:
  print(max(max(l1),c))
else:
  print(c)