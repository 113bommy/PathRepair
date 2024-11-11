from math import ceil
n,k=map(int,input().split())
a=sorted(list(map(int,input().split())))
f=sorted(list(map(int,input().split())),reverse=True)
l=[]
for i in range(n):
  l.append([f[i]*a[i],a[i],f[i]])
l.sort()
ng=-1
ok=l[n-1][0]
while ok-ng>1:
  mid=(ok+ng)//2
  cnt=0
  for i in range(n):
    if l[i][0]>mid:
      cnt+=ceil((l[i][0]-mid)/l[i][2])
  if cnt<=k:
    ok=mid
  else:
    ng=mid
print(ok)
