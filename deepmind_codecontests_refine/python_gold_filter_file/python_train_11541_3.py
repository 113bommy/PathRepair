from fractions import gcd

a, b, c = map(int, input().split())

if c%gcd(a, b):
  print("NO")
else:
  print("YES")