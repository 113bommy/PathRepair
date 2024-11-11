from fractions import gcd
S = lambda x: 1 if x==0 else A(x-gcd(x,a))
A = lambda x: 0 if x==0 else S(x-gcd(x,b))
a, b, c = map(int, input().split())
print(S(c))
