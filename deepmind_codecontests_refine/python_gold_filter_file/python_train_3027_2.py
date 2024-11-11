import math
a,b,C = [float(s) for s in input().split(' ')]

C = math.radians(C)

h = b * math.sin(C)
S = a * h * 0.5
L = a + b + math.sqrt(a**2 + b**2 - 2*a*b*math.cos(C))

print(S)
print(L)
print(h)