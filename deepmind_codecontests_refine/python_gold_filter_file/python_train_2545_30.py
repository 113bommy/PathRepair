x1,y1,x2,y2=map(int,input().split())
if x1>x2:
    x1,x2=x2,x1
    y1,y2=y2,y1
if ((x1!=x2 and y1!=y2) and (x2!=y2) and abs(x1-x2)!=abs(y1-y2)):
    print(-1)
    exit(0)
elif x1==x2:
    a=abs(y1-y2)
    x3=x1+a
    x4=x1+a
    y3=y1
    y4=y2
elif y1==y2:
    b=abs(x1-x2)
    y3=y1+b
    y4=y1+b
    x3=x1
    x4=x2
else:
    x3=x1
    x4=x2
    y3=y2
    y4=y1
print(x3,y3,x4,y4)