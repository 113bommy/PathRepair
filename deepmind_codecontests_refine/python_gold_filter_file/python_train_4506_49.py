MOD = 1000000007
from collections import defaultdict as dd, Counter, deque


def si(): return input()


def ii(): return int(input())


def li(): return list(map(int, input().split()))


def mi(): return map(int, input().split())


def out(v): print(v)


def spout(): print(v, end=" ")


def d2b(n): return bin(n).replace("0b", "")


def twod(n, m, num): return [[num for x in range(m)] for y in range(n)]


def vow(): return ['a', 'e', 'i', 'o', 'u']


def let(): return [chr(i) for i in range(97, 123)]


def gcd(x, y):
    while y:
        x, y = y, x % y
    return x


def ispow2(x):
    return (x and (not (x & (x - 1))))


def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1: factors.append(n)
    return (list(factors))

t=ii()
while t:
    t-=1
    a,b,c=mi()
    print(a+b+c-1)