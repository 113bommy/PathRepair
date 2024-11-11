import math
a,b,h,m = map(int,input().split())
x = a**2+b**2-2*a*b*math.cos(math.radians(30*h+0.5*m-6*m))
print(x**(1/2))
