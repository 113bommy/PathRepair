a,b,c=map(int,input().split())
if a+b>=c:
  print(b+c)
else:
  print(a+2*min(b,c)+1)