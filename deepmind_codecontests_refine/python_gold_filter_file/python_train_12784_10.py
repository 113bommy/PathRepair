n,x=map(int,input().split())
l=list(map(int,input().split()))
d=0
c=1
for i in range (0,n):
  d=d+l[i]
  if d<=x:
    c+=1
print(c)