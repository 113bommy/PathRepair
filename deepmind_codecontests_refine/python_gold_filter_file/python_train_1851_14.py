n,d=map(int,input().split())
c=0
for i in range(n):
  x,y=map(int,input().split())
  if x*x+y*y<=d*d:
    c+=1
print(c)
