from math import gcd, floor

x = int(input())
r = 0
i = 1
while i**2 <= x:
    if not x % i:
        f = floor(x/i)
        lcm = i/gcd(i, f) * f
        if lcm == x:
            r = i
    i += 1
print(str(r) + " " + str(floor(x / r)))
