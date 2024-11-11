from sys import stdin
from math import gcd
input = stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    used = [False]*n
    cur = 0
    b = []
    for j in range(n):
        best = 0
        for i in range(n):
            if used[i]:
                continue
            g = gcd(cur, a[i])
            if g > best:
                best = g
                best_idx = i
        used[best_idx] = True
        cur = best
        b.append(a[best_idx])
    print(*b)