import math
l=[int(x) for x in input().split()]
r=l[0]
x,y=l[1],l[2]
xc,yc=l[3],l[4]
if xc==x and yc==y:
    print(0)
else:
    dist=math.sqrt((xc-x)**2+(yc-y)**2)
    dist=math.ceil(dist)
    #print(dist)
    #print(2*r)
    ans=math.ceil(abs(dist)/(2*r))
    print(ans)