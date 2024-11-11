from math import *

def euclid(x1,y1,x2,y2):
    x = x2-x1
    y = y2-y1
    return sqrt(x*x + y*y)

r,x1,y1,x2,y2 = map(int,input().split())
print(ceil(euclid(x1,y1,x2,y2)/(2*r)))