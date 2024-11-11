import math
a,b,c = map(int,input().split())
c=c/180*math.pi
print(0.5*a*b*math.sin(c),a+b+(a**2+b**2-2*a*b*math.cos(c))**0.5,b*math.sin(c))
