n,d=map(int,input().split())
ctr=0
for i in range(n):
  x,y=map(int,input().split())
  t=(x**2+y**2)**(1/2)
  if t<=d:
    ctr+=1
print(ctr)
