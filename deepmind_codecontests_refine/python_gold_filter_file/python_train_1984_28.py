import math

x1,y1,x2,y2= map(float,(input().split()))

D=(x2-x1)**2+(y2-y1)**2
d= math.sqrt(D)
print(d)