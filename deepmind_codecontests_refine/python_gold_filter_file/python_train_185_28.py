from collections import Counter

N, P = map(int, input().split())

def prime_factorization(n):
    factor = []
    f = 2
    while f ** 2 <= n:
        if n % f == 0:
            factor.append(f)
            n //= f
        else:
            f += 1
    if n > 1:
        factor.append(n)
    return factor

p = prime_factorization(P)
c = Counter(p)

l = []
j = []
for k, v in c.items():
    if N <= v:
        l.append(k)
        j.append(v//N)
ans = 1

for i,v in zip(l,j):
    ans *= i**v

print(ans)