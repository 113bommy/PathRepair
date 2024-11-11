n,x=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
for i in range(n):
  x-=a[i]
  if(x<0):
    break
if(x!=0):
  print(i)
else:
  print(n)