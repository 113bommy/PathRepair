import math,sys
x1,y1,x2,y2 = map(int,input().split())
x3 = x4 = y3 = y4 = 0
if x1 == x2:
    x3 = x1+abs(y2-y1)
    y3 = y1
    x4 = x2+abs(y2-y1)
    y4 = y2
elif y1 == y2:
    y3 = y1 + abs(x2-x1)
    x3 = x1
    y4 = y2 + abs(x2-x1)
    x4 = x2
else:
    d = int((pow((x2-x1),2)+pow((y2-y1),2))//2)
    # print ("d ",d)
    if abs((y2-y1)/(x2-x1)) != 1:
        print (-1)
        sys.exit(0)
    else:
        d = int(d)
        if(y1>y2):
            y1,y2 = y2,y1
            x1,x2 = x2,x1
        x3 = x1
        y3 = y2
        x4 = x2
        y4 = y1
print (x3,y3,x4,y4)