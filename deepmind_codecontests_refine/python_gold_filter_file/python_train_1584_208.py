n = int(input())

from math import sqrt

def gcd(a, b):
    if not a:
        return b
    return gcd(b%a, a)

def checkPrime(m):
    for i in range(2, int(sqrt(m) + 1)):
        if gcd(i, m) != 1:
            return False
    return True

for i in range(2, 10 ** 7):
    a = i + n
    b = i 
#    print(a, b)
    if not checkPrime(a) and not checkPrime(b):
        print(a, b)
        break

