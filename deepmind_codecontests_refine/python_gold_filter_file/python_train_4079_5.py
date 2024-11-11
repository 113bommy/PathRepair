import sys
t=int(sys.stdin.readline())
for _ in range(t):
    n=int(sys.stdin.readline())
    x1=y1=-10**5
    y2=x2=10**5
    for i in range(n):
        a=[0]+list(map(int,sys.stdin.readline().split()))
        if a[3]==0:
            x1=max(a[1],x1)
        if a[4]==0:
            y2=min(a[2],y2)
        if a[5]==0:
            x2=min(a[1],x2)
        if a[6]==0:
            y1=max(a[2],y1)
    if x1<=x2 and y1<=y2:
        print(1,x1,y1)
    else:
        print(0)