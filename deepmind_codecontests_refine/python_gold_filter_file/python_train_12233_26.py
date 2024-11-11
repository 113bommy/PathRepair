from math import sqrt

def refine(n):
    for i in range(2,int(sqrt(n))+1):
        if n % i**2 == 0:
            n = n / i
            return n
            break
    return n

n = int(input())
previousN = 0

while n != previousN:
    previousN = n
    n = refine(previousN)

print(int(n))

    