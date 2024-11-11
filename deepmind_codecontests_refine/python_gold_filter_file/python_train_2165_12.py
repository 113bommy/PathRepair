n=int(input())
a=list(map(int,input().split()))
if 1 not in a:
  print(-1)
else:
  x=1
  for i in range(n):
    if a[i]==x:
      x+=1
  print(n-x+1)