import sys
import math

N = 1000000
primes = [1] * N
primes[0] = 0
primes[1] = 0
primes[4::2] = [0] * len(primes[4::2])

for i in range(3,int(math.sqrt(N)),2):
    if primes[i]:
        primes[i*i::i*2] = [0] * len(primes[i*i::i*2])

for i in sys.stdin:
        n = int(i)
        print(sum(primes[0:n+1]))