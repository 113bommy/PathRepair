import math
import sys
import collections
import itertools


# imgur.com/Pkt7iIf.png

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
def sieve(n):
    prime = [True for i in range(n + 1)]
    p = 2
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * 2, n + 1, p):
                prime[i] = False
        p += 1
    prime[0] = prime[1] = False
    r = [p for p in range(n + 1) if prime[p]]
    return r
def cdiv(n, k): return n // k + (n % k != 0)
def ii(): return int(input())
def mi(): return map(int, input().split())
def li(): return list(map(int, input().split()))
def lcm(a, b): return abs(a * b) // math.gcd(a, b)
def prr(a, sep = ' '): print(sep.join(map(str, a)))
def dd(): return collections.defaultdict(int)

s = input()
d = [ord(i)-96 for i in s]
t = collections.Counter(d)
r = []
for i in range(len(s)-1, -1, -1):
    f = True
    for j in range(1, d[i]):
        if t[j] > 0:
            r.append('Ann')
            f = False
            break
    if f: r.append('Mike')
    t[d[i]] -= 1

[print(i) for i in r[::-1]]



