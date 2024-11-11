from fractions import gcd
n,m = map(int,input().split())
s = input()
t = input()
x = gcd(n,m)
for i in range(x):
  if s[i*n//x]!=t[i*m//x]:
    print(-1)
    break
else:
  print(n*m//x)