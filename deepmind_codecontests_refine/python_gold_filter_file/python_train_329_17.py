def egcd(a, b):
  x,y, u,v = 0,1, 1,0
  while a != 0:
    q, r = b//a, b%a
    m, n = x-u*q, y-v*q
    b,a, x,y, u,v = a,r, u,v, m,n
  gcd = b
  return int(gcd), int(x), int(y)
 
n, D, a, b = map(int, input().split())
d, x, y = egcd(a, b)
 
if (D%d != 0):
  print ("-1")
  exit()
 
x *= D//d;
y *= D//d;
 
if (y < 0):
  up = ( (0 - y) + (a//d - 1) ) // (a//d);
  x -= (b//d) * up;
  y += (a//d) * up;
 
if (y > a//d):
  drop = (y-1) // (a//d);
  x += b//d * drop;
  y -= a//d * drop;
 
if (x < 0):
  print ("-1")
  exit()
 
rem = n - (x+y)
if (rem < 0):
    print ("-1")
else:
    print (x, y, rem)

