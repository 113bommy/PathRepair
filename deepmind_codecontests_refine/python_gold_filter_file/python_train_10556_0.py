a=input().split()

x=int(a[0])
y=int(a[1])

if x<0:
    if y>0:
        x1=x-y
        x2=0
        y1=0
        y2=y-x
    else:
        x1=x+y
        x2=0
        y1=0
        y2=x+y
elif x>0:
    if y>0:
        x1=0
        x2=x+y
        y1=x+y
        y2=0
    else:
        x1=0
        x2=x-y
        y1=y-x
        y2=0
print(x1,y1,x2,y2)