from math import sqrt,ceil
r,x,y,x1,y1=list(map(int,input().split()))
r1=(sqrt((x-x1)**2 + (y-y1)**2))
#print(r1)
y=(2*r)
print(ceil(r1/y))
