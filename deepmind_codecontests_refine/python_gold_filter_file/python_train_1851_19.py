n,d=map(int,input().split())
s=0
for _ in range(n):
  x,y=map(int,input().split())
  if x**2+y**2<=d**2:s+=1
print(s)