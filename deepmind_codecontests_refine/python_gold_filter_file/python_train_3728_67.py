x,y,z,k=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=list(map(int,input().split()))
l=[]
L=[]
for ix in range(x):
  for iy in range(y):
    l.append(a[ix]+b[iy])
l.sort()
l.reverse()
if len(l)>k:
  l=l[0:k]
for iz in range(z):
  for i in range(len(l)):
    L.append(c[iz]+l[i])
L.sort()
L.reverse()
for i in range(k):
  print(L[i])