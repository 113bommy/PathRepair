import math
from random import randint
from sys import stdout


def gcd(a, b):
    if b == 0:
        return a
    if a == 0:
        return b
    if not a & 1 and not b & 1:
        return gcd(a >> 1, b >> 1) << 1
    if a & 1 and not b & 1:
        return gcd(a, b >> 1)
    if b & 1 and not a & 1:
        return gcd(a >> 1, b)
    if a > b:
        return gcd(a - b, b)
    return gcd(b - a, a)


def factor(n):
    global N
    if n == 1:
        return []
    if n == 2 or n == 3 or n == 5 or n == 7:
        return [n]
    k = 8
    for i in range(k):
        x = randint(1, N - 1)
        if math.gcd(n, x) != 1:
            y = 0
            break
        stdout.write('sqrt %d\n' % (x * x % N))
        stdout.flush()
        y = int(input()) % n
        if x != y and (x + y) % n != 0 and (x - y) % n != 0:
            break
        if i == k - 1:
            return [n]

    d = math.gcd(n, abs(x - y))
    if d == 1 or d == n:
        return [n]
    d1 = factor(d)
    d2 = factor(n // d)
    return d1 + d2


# a = int(input())
# b = int(input())
# N = a * b
N = int(input())

s = factor(N)
print('!', len(s), *s)
