from math import sqrt,ceil
r,x,y,X,Y = [int(i) for i in input().split()]

dist = sqrt((x-X)**2+(y-Y)**2)
print(ceil(dist/(2*r)))