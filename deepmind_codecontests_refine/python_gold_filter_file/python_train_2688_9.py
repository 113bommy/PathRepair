from fractions import gcd
n,m = map(int,input().split())
s = input()
t = input()
x = gcd(n,m)
if s[::n//x]==t[::m//x]:
  print(n*m//x)
else:
  print(-1)