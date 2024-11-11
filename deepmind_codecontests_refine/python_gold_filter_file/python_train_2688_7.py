from fractions import gcd
n,m=map(int,input().split())
s = input()
t = input()
g = gcd(n,m)
ng = n//g
mg = m//g
for i in range(g):
    if s[ng*i]!=t[mg*i]:
        print("-1")
        break
else:
    print(n*m//g)