import math

mod = 10 ** 9 + 7
x, n = map(int, input().split())

def mu(a, b):
    if (b == 0):
        return 1
    temp = mu(a, b // 2)
    temp = (temp * temp) % mod
    if (b % 2):
        temp = (temp * a) % mod
    
    return temp

def d(x, a, b):
    return x // a - x // (a * b)

def phantich(n):
    res = []
    w = int(math.sqrt(n)) + 1
    for i in range(2, w):
        if (n % i == 0):
            res.append(i)
        while n % i == 0:
            n //= i
    
    if (n > 1):
        res.append(n)

    return res

p = phantich(x)

answer = 1
for w in p:
    temp = w
    while (n >= temp):
        q = d(n, temp, w)
        answer = (answer * mu(temp, q)) % mod
        temp = temp * w

print(answer)