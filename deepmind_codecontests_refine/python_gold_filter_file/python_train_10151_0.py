from math import gcd
t, w, b = map(int, input().split())
c = w * b // gcd(w, b)
p = min(t, min(w, b) - 1)
if t >= c:
    p += (t // c - 1) * min(w, b)
    x = t // c * c
    p += min(w, b, (t - x + 1))
q = t
g = gcd(p, q)
p //= g
q //= g
print(p, q, sep = '/')

