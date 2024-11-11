h,w=map(int,input().split())
n=int(input())
c=list(map(int,input().split()))
d=[]
for i in range(1,n+1):
  for j in range(c[i-1]):
    d.append(i)
ansl=[[0]*w for i in range(h)]
for i in range(h):
  if i%2==0:
    for j in range(w):
      ansl[i][j]=str(d[i*w+j])
  else:
    for j in range(w):
      ansl[i][w-j-1]=str(d[i*w+j])
for j in ansl:
  print(" ".join(j))
