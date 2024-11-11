a,b,c = map(int,input().split())
if c <= b+a+1:
  print(b+c)
else:
  print(2*b+a+1)
