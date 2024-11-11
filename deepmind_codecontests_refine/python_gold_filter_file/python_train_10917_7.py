import sys

def gcd(m, n):
    r = m % n
    if r == 0:
        return n
    else:
        return gcd(n, r)

lines = sys.stdin.readlines()
for line in lines:
    a, b = map(int, line.split())
    m = max(a, b)
    n = min(a, b)
    print(gcd(m, n), m * n // gcd(m, n))