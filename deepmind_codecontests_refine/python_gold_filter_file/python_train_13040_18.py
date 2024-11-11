import math
t=int(input())
while(t>0):
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    amin=min(a)
    bmin=min(b)
    op=0
    for i in range(n):
        x1=a[i]-amin if(a[i]-amin)>0 else 0
        x2=b[i]-bmin if(b[i]-bmin)>0 else 0
        d= x1 if(x1>x2) else x2
        op= op + d
    t=t-1
    print(op)
