from math import *

a, b = map(int, input().split())
if a == b:
    print('infinity')
    exit(0)

t = a - b

def primes_sieve(limit):
    limitn = limit+1
    not_prime = [False] * limitn
    primes = []

    for i in range(2, limitn):
        if not_prime[i]:
            continue
        for f in range(i*2, limitn, i):
            not_prime[f] = True

        primes.append(i)

    return primes

lst = primes_sieve(trunc(sqrt(10**10+7)))

def factorize(n, primes):
    factors = []
    for p in primes:
        if p*p > n: break
        i = 0
        while n % p == 0:
            n //= p
            i+=1
        if i > 0:
            factors.append((p, i));
    if n > 1: factors.append((n, 1))

    return factors
    
def divisors(factors):
    div = [1]
    for (p, r) in factors:
        div = [d * p**e for d in div for e in range(r + 1)]
    return div


dv = divisors(factorize(t, lst))
c = 0
for x in dv:
    if x > b:
        c+=1
print(c)
#print(dv)
