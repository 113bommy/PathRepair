from collections import Counter

nn = int(input())

def get_primes(up_to):
    res = []
    for p in range(2, up_to+1):
        flag = False
        for q in res:
            if q*q > p: 
                break
            if p%q == 0:
                flag = True
                break
        if not flag:
            res.append(p)
    return res
 
primes = get_primes(int(1000000000**0.5))
primes_set = set(primes)

def get_prime_divisors(x):
    res = Counter()
    if x in primes_set:
        res[x] += 1
        return res
    for prime in primes:
        while x%prime == 0:
            x = x//prime
            res[prime] += 1
        if x in primes_set:
            res[x] += 1
            return res
    if x > 1:
        res[x] += 1
    return res

def get_fix_prime_divisors(x, fix_primes):
    res = Counter()
    for prime in fix_primes:
        while x%prime == 0:
            x = x//prime
            res[prime] += 1
    return res

def main(p, q):
    q_primes = get_prime_divisors(q)
    p_primes = get_fix_prime_divisors(p, q_primes)
    minim = 10E18
    for prime in q_primes:
        diff = p_primes[prime] - q_primes[prime]
        if diff < 0:
            return(p)
        minim = min(minim, prime**(diff+1))
    return p//minim
   
for _ in range(nn):
    p, q = [int(s) for s in input().split()]
    print(main(p, q))