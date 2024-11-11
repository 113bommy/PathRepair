import math
a,b,h,m=map(int,input().split())
h=h*30+0.5*m
m=m*6
x=abs(h-m)
print(math.sqrt(a**2+b**2-2*a*b*math.cos(math.radians(x))))