from fractions import gcd
a,b,c=map(int,input().split())
d=gcd(a,b)
if c%d==0:
  print("YES")
else:
  print("NO")
