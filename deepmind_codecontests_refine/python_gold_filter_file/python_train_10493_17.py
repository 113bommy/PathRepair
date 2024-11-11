import math
a,b,x=map(int,input().split())
if a**2*b>=2*x:
    print(math.degrees(math.atan2(a*b**2,(2*x))))
else:
    print(math.degrees(math.atan2(2*b*a**2-2*x,a**3)))