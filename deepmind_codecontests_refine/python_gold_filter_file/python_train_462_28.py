l=lambda:map(int,input().split())
r,x,y,x1,y1=l()
d=((x-x1)**2+(y-y1)**2)**0.5
from math import ceil
print(int(ceil(d/(2*r))))
