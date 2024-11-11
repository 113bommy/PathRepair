import sys
import os
import math

def READ(fileName):
    sys.stdin = open('in.txt')


def sieve():
    primes = []
    M = 100007
    marked = [0 for x in range(M)]
    sz = int(math.sqrt(M))
    for i in range(3, sz, 2):
        if marked[i] == 0:
            for j in range(i*i, M, 2*i):
                marked[j] = 1

    primes.append(2)

    for i in range(3, M, 2):
        if marked[i] == 0:
            primes.append(i)

    return primes 

def g(x, p):
    cnt = 0

    while x != 0:
        cnt += x//p
        x //= p

    res = pow(p, cnt, 1000000007)
    return res

if __name__ == "__main__":
    #READ('in.txt')
    mod = 1000000007
    while True:
        try:
            x, n = map(int, input().split())
        except EOFError:
            break
        
        primes = sieve()
        factors = []

        for prime in primes:
            if x % prime == 0:
                factors.append(prime)
                while x % prime == 0:
                    x //= prime

        if x > 1:
            factors.append(x)
        #print(factors)
        res = 1
        for factor in factors:
            #res *= g(n, factor)
            res = ((res % mod) * (g(n, factor) % mod)) % mod
        
        print(res)

    pass