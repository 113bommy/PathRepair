from math import atan, degrees
a,b,x = map(int,input().split())
if x >= (a**2)*b/2:
    tan = (2*b*a**2-2*x)/a**3
else:
    tan = a*b**2/(2*x)
print(degrees(atan(tan)))