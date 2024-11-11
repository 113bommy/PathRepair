n,k=map(int,input().split())
ar=list(map(int,input().split()))
d={}
flag=True
for i in range(n):
  if ar[i] in d:
   d[ar[i]].append(i)
   if len(d[ar[i]])>k:
    print('NO')
    flag=False
    break
  else:d[ar[i]]=[i]
if flag:
  c=0
  r=[0]*n
  print('YES',end=" ")
  for x in d:
   for j in d[x]:
     c=c%k+1
     r[j]=c
     
  print(*r)
