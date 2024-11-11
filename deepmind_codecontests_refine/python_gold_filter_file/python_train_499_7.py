a,b,c,x,y=map(int, input().split())
if x>y:
  print(min(a*x+b*y,2*c*y+a*(x-y),2*c*x))
else:
  print(min(a*x+b*y,2*c*x+b*(y-x),2*c*y))