x,a,b=map(int,input().split())
if abs(a-x)>abs(x-b):
  print("B")
else:
  print("A")