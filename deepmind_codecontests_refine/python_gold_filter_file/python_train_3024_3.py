import math
a, b, C = map(int, input().split())
rad = C / 180 * math.pi
h = b * math.sin(rad)
S = a * h / 2
c = math.sqrt(h**2 + (a-b*math.cos(rad))**2)
L = a + b + c
print(S, L, h)