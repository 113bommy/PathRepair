x,y=list(map(int,input().split()))
x1,x2,y1,y2=0,0,0,0
if x<0:
    if y<0:
        x1=x+y
        y2=y+x
    else:
        x1=x-y
        y2=y-x
else:
    if y<0:
        x2=x-y
        y1=y-x
    else:
        x2=x+y
        y1=y+x
print(x1,y1,x2,y2)