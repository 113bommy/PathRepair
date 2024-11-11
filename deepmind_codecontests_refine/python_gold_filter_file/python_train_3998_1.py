n=int(input())
a=[int(x) for x in input().split()]
b=[]
g=False
o=[]
for i in range(n):
  if g:
    break
  elif (a[i] in b)==False:
    for x in range(i,n-1):
      if a[i]+a[x+1] in a:
        o=[1+a.index(a[i]+a[x+1]),1+i,x+2]
        g=True
        break
    b+=[a[i]]
if g:
  print(*o)
else:
  print(-1)