a=int(input())
b=list(map(int,input().split()))
c=sorted(b)
d=0
for i in range(a):
  if b[i]!=c[i]:
    d+=1
if d<=2:
  print('YES')
else:
  print('NO')