n,d=map(int,input().split())
l=0
for i in range(n):
  x,y=map(int,input().split())
  if x**2+y**2<=d**2:
    l+=1
print(l)
