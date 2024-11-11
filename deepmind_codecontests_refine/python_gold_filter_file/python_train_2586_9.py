n=int(input())
a=[int(input())-1 for i in range(n)]
c,x=1,0
for i in range(n):
  x=a[x]
  if x==1:
    print(i+1)
    break
else:
  print(-1)