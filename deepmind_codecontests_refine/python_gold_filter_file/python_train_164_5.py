def d(x,y,xx,yy):return ((x-xx)**2+(y-yy)**2)
x1,y1,x2,y2,x3,y3=map(int,input().split())
print(['NO','YES'][d(x1,y1,x2,y2)==d(x2,y2,x3,y3)and(y2-y1)*(x3-x2)!=(y3-y2)*(x2-x1)])