from fractions import gcd
n,k = map(int,input().split())
a = list(map(int,input().split()))
g = a[0]
for i in range(n):
  g = gcd(g,a[i])
if k%g == 0 and k <= max(a):
  print("POSSIBLE")
else:
  print("IMPOSSIBLE")