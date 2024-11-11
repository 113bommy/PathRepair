import math
a,b,h,m=map(int,input().split())
x=a**2+b**2-2*a*b*math.cos(math.radians(6*m-30*(h+m/60)))
print(math.sqrt(x))