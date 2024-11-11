import math

a, b, c = map(int, input().split())

d = math.gcd(a, b)

print("YES" if c % d == 0 else "NO")
