from math import*
a,b,x=map(int,input().split())
print(atan(2*(b/a-x/a**3)if x>a**2*b/2else a*b**2/2/x)/pi*180)