n,a,b = [int(i) for i in input().split()]
if (b - a)%2:
  print((b-a)//2 + 1 + min(a-1,n-b))
else:
  print((b-a)//2)