import math
r,x1,y1,x2,y2=map(int,input().split())
d=math.sqrt((x2-x1)**2+(y2-y1)**2)
x=d//(2*r)
if(d%(2*r)!=0):
    x+=1
print(int(x))