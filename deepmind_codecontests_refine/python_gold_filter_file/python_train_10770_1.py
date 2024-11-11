# import sys, io, os
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


def solve(n,l,x,y,a):
    s=set()
    fx,fy,fxy,fyx=False,False,False,False
    vxy=-1
    vyx_min,vyx_max=-1,-1
    for v in a:
        if v-x in s:
            fx=True
        if v-y in s:
            fy=True
        if v-(x+y) in s:
            fxy=True
            vxy=v
        if v-(y-x) in s:
            if not fyx:
                fyx=True
                vyx_min=vyx_max=v
            else:
                vyx_max=v

        s.add(v)
    if fx and fy:
        print(0)
    elif fx:
        print(1)
        print(y)
    elif fy:
        print(1)
        print(x)
    elif fxy:
        print(1)
        print(vxy-y)
    elif fyx:
        if vyx_min+x<l:
            print(1)
            print(vyx_min+x)
        elif vyx_max-y>0:
            print(1)
            print(vyx_max-y)
        else:
            print(2)
            print(x,y)
    else:
        print(2)
        print(x,y)
        
n,l,x,y=map(int,input().split())
a=list(map(int,input().split()))
solve(n,l,x,y,a)
