import sys
input = sys.stdin.readline

t=int(input())
for ll in range(t):
    n=int(input())
    maxy=10**5
    miny=-10**5
    maxx=10**5
    minx=-10**5
    for i in range(n):
        x, y, f1, f2, f3, f4=map(int, input().split())
        if f2==0:
            maxy=min(maxy, y)
        if f4==0:
            miny=max(miny, y)
        if f3==0:
            maxx=min(maxx, x)
        if f1==0:
            minx=max(minx, x)
    if minx>maxx or miny>maxy:
        print(0)
    else:
        print(1, minx, miny)
'print(1, minx+((maxx-minx)//2), miny+((maxy-miny)//2))'