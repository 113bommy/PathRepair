r,d,x0 = map(int,input().split())

x=x0
for i in range(10):
  x=r*x-d
  print(x)
