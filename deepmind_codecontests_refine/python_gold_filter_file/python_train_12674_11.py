import sys
from math import sqrt,ceil,gcd

def sieve(N):
    b = [True]*(N+1)
    b[0] = False
    b[1] = False

    lim = ceil(sqrt(N))
    i = 2
    while i <= lim:
        if b[i]:
            for n in range(i**2,N+1,i):
                b[n] = False
        i+=1
    
    return [i for i,b in enumerate(b) if b]

P = sieve(10**5)

def factor(n,P):
    """Given prime list, factorize n"""
    if n in P: return [n]
    f = []
    for p in P:
        while n%p == 0:
            n//=p
            f.append(p)
        if n in P:
            f.append(n)
            return f
    if n != 1:
        f.append(n)
    return f

def divisors(n):
    F = factor(n,P)
    D = {1}
    for f in F:
        D |= {f*d for d in D}
    return D

l,r,x,y = map(int,input().split())

a = x
if y%a != 0:
    print(0)
    sys.exit()

x//=a
y//=a

cnt = 0
for d in divisors(y):
    n = d*a
    m = y//d*a
    if l<=n<=r and l<=m<=r and gcd(d,y//d) == 1:
        cnt += 1
print(cnt)
