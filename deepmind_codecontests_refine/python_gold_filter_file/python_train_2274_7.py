from fractions import gcd
n,k = map(int,input().split())
a = [int(i) for i in input().split()]
g = a[0]
for i in a:
  g = gcd(g,i)
  
if k%g != 0:
  print('IMPOSSIBLE')
elif k<=max(a):
  print('POSSIBLE')
else:
  print('IMPOSSIBLE')