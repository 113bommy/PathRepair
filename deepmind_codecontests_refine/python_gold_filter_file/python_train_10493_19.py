from math import*
a,b,x=map(int,input().split())
print(atan(a*b*b/2/x*(x<a*a*b/2)or(b/a-x/a**3)*2)/pi*180)