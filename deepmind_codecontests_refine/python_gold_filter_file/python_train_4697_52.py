import math

a, b, c = input().split()
a = int(a)
b = int(b)
c = int(c)
t = 0

maxx = max(max(a,b),c)
minn = min(min(a,b),c)
midd = a + b + c - minn - maxx
if  maxx - midd - minn >= 0:
    t = maxx - midd - minn + 1
print(t)
        
