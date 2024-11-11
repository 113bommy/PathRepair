import math
a, b, h, m = map(int, input().split())

l = a**2 + b**2 - 2*a*b*math.cos(math.radians(5.5*(h*60+m)))
print(math.sqrt(l))