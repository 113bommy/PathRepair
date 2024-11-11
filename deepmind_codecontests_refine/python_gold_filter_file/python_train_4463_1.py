from fractions import gcd
a,b,c,d=map(int,input().split())
if abs(c-a)==0 or abs(d-b)==0:
  print(0)
else:
  x,y=abs(c-a),abs(d-b)
  g=gcd(x,y)
  print(x+y-g)
