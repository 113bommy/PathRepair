a,b=map(int,input().split())
c=0
for i in range(a+1):
  for j in range(a+1):
    z=b-(i+j)
    if 0<=z<=a:
      c+=1
print(c)