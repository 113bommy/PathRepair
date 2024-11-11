import sys
from collections import Counter
import itertools

def input():
    return sys.stdin.readline().strip()

def dinput():
    return int(input())

def tinput():
    return input().split()

def rinput():
    return map(int, tinput())

def f(a):
    t = 1
    for i in range(a):
        t *= (i + 1)
    return t

def cor(n, k):
    return int(f(n) / (f(k) * f(n - k)))

def main():
    k, n, a, b = rinput()
    t = b * n
    if t >= k:
        print(-1)
    else:
        a -= b
        k -= t + 1
        print(min(k//a, n))
for i in range(int(input())):
    main()