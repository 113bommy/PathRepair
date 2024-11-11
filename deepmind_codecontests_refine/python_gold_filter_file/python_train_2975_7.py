ax,ay=[int(i) for i in input().split()]
bx,by=[int(i) for i in input().split()]
cx,cy=[int(i) for i in input().split()]
a=bx-ax
b=by-ay
c=cx-ax
d=cy-ay
if a*d-b*c==0:
    print(0)
else:
    print(3)
    print(ax+bx-cx,ay+by-cy)
    print(ax+cx-bx,ay+cy-by)
    print(cx+bx-ax,cy+by-ay)