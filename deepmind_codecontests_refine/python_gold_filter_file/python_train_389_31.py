from math import gcd
N = int(input())
A = list(map(int,input().split()))

g = 0
for a in A:
    g = gcd(g,a)
if g > 1:
    print('not coprime')
    exit()

def factorize(n):
    d = set()
    m = 2
    while m*m <= n:
        while n%m == 0:
            n //= m
            d.add(m)
        m += 1
    if n > 1:
        d.add(n)
    return d

st = set()
for a in A:
    fac = factorize(a)
    if fac & st:
        print('setwise coprime')
        exit()
    st |= fac
print('pairwise coprime')