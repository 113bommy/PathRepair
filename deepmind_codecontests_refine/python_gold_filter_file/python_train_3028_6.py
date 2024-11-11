from math import *
a,b,c = map(int,input().split())
c = radians(c)
S = a*b*sin(c)/2
print("%.10f %.10f %.10f" %(S,a+b+sqrt(a*a+b*b-2*a*b*cos(c)),2*S/a ))
