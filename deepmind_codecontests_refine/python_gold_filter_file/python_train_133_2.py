import math
import sys
input = sys.stdin.readline

#Check if a number is prime or not in O(n**0.5)
def chkPrime(n):
    flag = 1
    for i in range(2,int(n**0.5)+1):
        if n%i == 0:
            flag = 0
            break

    return flag

#Returns set prime factors O(sqrt(n))
def primefactors(n):
    l = []
    while n % 2 == 0:
        l.append(2)
        n = n // 2

    for i in range(3, int(math.sqrt(n)) + 1, 2):
        while n % i == 0:
            l.append(i)
            n = n // i

    if n > 2:
        l.append(n)

    return l

q = int(input())
if q == 1 or chkPrime(q):
    print(1)
    print(0)
    exit()

w = primefactors(q)
if len(w) == 2:
    print(2)
    exit()

prod = 1
for i in range(2):
    prod = prod*w[i]

# print("HI")
print(1)
print(prod)
