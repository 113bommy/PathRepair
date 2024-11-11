from sys import stdin
from math import ceil

def gcd(a, b):
    if b: return gcd(b, a%b)
    else: return a

def sno(g, n, y):
    return -(-y//(n//g))

n, m, q = map(int, stdin.readline().split())
g = gcd(n, m)

for i in range(q):
    sx, sy, ex, ey = map(int, stdin.readline().split())
    one, two = 0, 0
    if sx == 1:
        one = sno(g, n, sy)
    else:
        one = sno(g, m, sy)
    if ex == 1:
        two = sno(g, n, ey)
    else:
        two = sno(g, m, ey)
    if one == two: print("YES")
    else: print("NO")