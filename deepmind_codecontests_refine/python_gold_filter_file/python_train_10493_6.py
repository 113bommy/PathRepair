import math
a,b,x=(int(i) for i in input().split())
if x>=a*a*b*0.5:
    print(math.degrees(math.atan(2*b/a-2*x/a**3)))
else:
    print(math.degrees(math.atan(a*b*b/(2*x))))