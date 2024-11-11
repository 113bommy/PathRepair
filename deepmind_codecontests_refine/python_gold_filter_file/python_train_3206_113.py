a,b,c=map(int,input().split())
if a<=c:
  print(0,max(a+b-c,0))
else:
  print(a-c,b)