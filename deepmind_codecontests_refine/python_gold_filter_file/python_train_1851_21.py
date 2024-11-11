n,d=map(int,input().split())
c=0
for i in range(n):
  a,b=map(int,input().split())
  if a**2+b**2<=d**2:
    c+=1
print(c)