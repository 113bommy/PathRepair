import sys

def isPrime(num):
    if num <= 1:
        return False
    else:
        for i in range(2, int(num**(1/2))+1):
            if num%i == 0:
                return False
        else:
            return True
    
primes = []        
for i in range(2, 51):
    if isPrime(i) == True:
        primes.append(i)
        
a, b = map(int, sys.stdin.readline().split())

if a in primes and b in primes:
    if primes.index(b) - primes.index(a) == 1:
        print("YES")
    else:
        print("NO")
else:
    print("NO")