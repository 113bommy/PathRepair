n,r=map(int,input().split())
c=0
for i in range(n):
  x,y=map(int,input().split())
  if x**2+y**2<=r**2:
    c+=1
print(c)