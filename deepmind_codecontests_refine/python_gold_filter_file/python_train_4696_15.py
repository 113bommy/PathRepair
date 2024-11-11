import math
abxy = [int(asdf) for asdf in input().split()]
a = abxy[0]
b = abxy[1]
x = abxy[2]
y = abxy[3]
div = math.gcd(x,y)
x /= div
y /= div
print(int(min(a//x, b//y)))

