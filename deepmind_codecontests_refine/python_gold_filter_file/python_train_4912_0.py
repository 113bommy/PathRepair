import math
import itertools
import collections

def getdict(n):
    d = {}
    if type(n) is list:
        for i in n:
            if i in d:
                d[i] += 1
            else:
                d[i] = 1
    else:
        for i in range(n):
            t = ii()
            if t in d:
                d[t] += 1
            else:
                d[t] = 1
    return d
def cdiv(n, k): return n // k + (n % k != 0)
def ii(): return int(input())
def mi(): return map(int, input().split())
def li(): return list(map(int, input().split()))
def lcm(a, b): return abs(a*b) // math.gcd(a, b)
def wr(arr): return ' '.join(map(str, arr))
def prime(n):
    if n == 2:
        return True
    if n % 2 == 0 or n <= 1:
        return False

    sqr = int(math.sqrt(n)) + 1

    for d in range(3, sqr, 2):
        if n % d == 0:
            return False
    return True
def revn(n):
    m = 0
    while n > 0:
        m = m * 10 + n % 10
        n = n // 10
    return m

n = ii()
a = sorted(set(li()))

if 1 in a or n == 1:
    print(1)
else:
    for i in range(1, len(a)):
        for j in range(i):
            if a[j] != 0 and a[i] % a[j] == 0:
                a[i] = 0
    print(len(a) - a.count(0))