import sys

def gcd(m, n):
    if n != 0:
        return gcd(n, m % n)
    else:
        return m

for line in sys.stdin.readlines():
    m, n = map(int, line.split())
    g = gcd(m, n)
    l = m * n // g    # LCM
    print(g, l)