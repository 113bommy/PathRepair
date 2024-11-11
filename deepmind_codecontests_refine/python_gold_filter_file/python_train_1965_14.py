# -*- coding;utf-8 -*-

def sieve(n):
    p = 0
    primes = []
    is_prime = [True]*(n+1)
    is_prime[0] = False
    is_prime[1] = False
    for i in range(2, n+1):
        if(is_prime[i]):
            primes.append(i)
            p += 1
            for j in range(i*2,n+1,i):#iごとに増える
                is_prime[j] = False
    return p

if(__name__ == "__main__"):
    while(True):
        try:
            n = int(input())
        except:
            break
        print(sieve(n))
        