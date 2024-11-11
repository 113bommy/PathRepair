def gcd(a, b):  
  if b == 0: return a
  return gcd(b, a % b)
n, m =  map(int, input().split())
g = gcd(n, m)
l = n * m // g
n = n//g
m = m//g
s = list(str(input()))[::int(n)]
t = list(str(input()))[::int(m)]
if s == t:
  print(l)
else:
  print("-1")