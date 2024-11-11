from math import sqrt
def prime(x):
    for i in range(2, int(sqrt(x)) + 1):
        if x % i == 0:
            return False
    return True
def nexxtprime(x):
    x0 = x
    while True:
        x += 1
        if prime(x) and not prime(x - x0):
            return x -x0
for i in range(int(input())):
    n = int(input())
    k = n - 1
    s = nexxtprime(k)
    for i in range(n):
        for j in range(n):
            if i == j:
                print(s, end=' ')
            else:
                print(1, end=' ')
        print()