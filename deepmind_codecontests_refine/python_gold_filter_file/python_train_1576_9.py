from math import sin,radians
n,r=map(int,input().split())
angle=360/(n*2)
#print(angle)
ratio=sin(radians(angle))
print((r*ratio)/(1-ratio))