gcd = lambda a,b: a if b==0 else gcd(b,a%b)
n,m = map(int,input().split())
s = input()
t = input()
a = m//gcd(n,m)
b = n//gcd(n,m)
if s[::b]==t[::a]:
    print(n*m//gcd(n,m))
else:
    print(-1)