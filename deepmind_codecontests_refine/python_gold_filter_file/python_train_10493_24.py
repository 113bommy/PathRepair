from math import atan, pi

a,b,x = map(int,input().split())
if x >= a**2*b/2:print(atan((b-x/a**2)*2/a)/pi*180)
else:print(atan(a*b**2/2/x)/pi*180)