import math
mod = 10**9+7
N = int(input())

iwashi01 = 0
iwashi10 = 0
iwashi00 = 0
iwashi = dict()
for i in range(N):
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        iwashi00 += 1
    elif a == 0:
        iwashi01 += 1
    elif b == 0:
        iwashi10 += 1            
    else:
        g = math.gcd(abs(a), abs(b))
        a //= g; b //= g
        if a*b > 0:
            if a < 0 and b < 0:
                a *= -1
                b *= -1
            iwashi.setdefault((a, b), [0, 0])
            iwashi[(a, b)][0] += 1
        if a*b < 0:
            if a < 0 and b > 0:
                a *= -1
                b *= -1
            a, b = -b, a
            iwashi.setdefault((a, b), [0, 0])
            iwashi[(a, b)][1] += 1

r = 2**iwashi01 % mod - 1 + 2**iwashi10 % mod - 1 + 1
for s, t in iwashi.values():
    r *= 2**s % mod -1 + 2**t % mod -1 + 1
    r %= mod
print((r + iwashi00 - 1) % mod)