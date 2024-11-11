import math


def prime_factors(n):
    l = []
    while n % 2 == 0:
        l.append(2)
        n = n / 2
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        while n % i == 0:
            l.append(i)
            n = n / i

    if n > 2:
        l.append(int(n))
    return l


n, k = map(int, input().split(" "))

if n==1:
    print(1)
else:
    l = prime_factors(n)
    if len(l)< k:
        print(-1)
    else:
        z = []
        for i in range(k-1):
            z.append(l[i])
        ex = 1
        for i in range(k-1, len(l)):
            ex*=l[i]
        if ex!=1:
            z.append(ex)
        print(*z)