def isInside(x,y,x1,y1,x2,y2):
    return x<x1 or x>x2 or y<y1 or y>y2
def fun(x):
    return 2*int(x)
    
x1,y1,x2,y2=list(map(fun,input().strip().split()))
x3,y3,x4,y4=list(map(fun,input().strip().split()))
x5,y5,x6,y6=list(map(fun,input().strip().split()))

for x in range(x1,x2+1):
    if(isInside(x,y1,x3,y3,x4,y4) and isInside(x,y1,x5,y5,x6,y6)):
        print("YES")
        exit(0)
    if(isInside(x,y2,x3,y3,x4,y4) and isInside(x,y2,x5,y5,x6,y6)):
        print("YES")
        exit(0)
for y in range(y1,y2+1):
    if(isInside(x1,y,x3,y3,x4,y4) and isInside(x1,y,x5,y5,x6,y6)):
        print("YES")
        exit(0)
    if(isInside(x2,y,x3,y3,x4,y4) and isInside(x2,y,x5,y5,x6,y6)):
        print("YES")
        exit(0)
print("NO")
    