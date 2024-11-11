n,h=map(int,input().split())
a,s=h/(2*n),0
for _ in range(n-1):
  l,r=0,h
  for i in range(50):
    mid=(l+r)/2
    x=mid/h
    if x*mid/2-s<=a:l=mid
    else: r=mid
  print(l,end=' ')
  x=l/h
  s=x*mid/2