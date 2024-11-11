from math import *
r,x,y,x1,y1=map(int,input().split())
d=((x-x1)**2+(y-y1)**2)**0.5
print(ceil(d/(2*r)))