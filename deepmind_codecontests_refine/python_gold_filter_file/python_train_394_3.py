n,x,*a=map(int, open(0).read().split())
a.sort()
for i in range(n):
    x-=a[i]
    if x<0:
      print(i)
      exit()
    elif x==0:
      print(-~i)
      exit()
print(n-1)