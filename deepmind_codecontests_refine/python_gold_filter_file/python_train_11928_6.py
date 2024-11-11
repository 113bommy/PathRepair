import math
k=int(input())
up=1000000000000000000000000000000000000000000000000000000000000000000000
down=-1*up
inf=0
a,b=map(int,input().split())
if b==2:
    up=1899+a
    inf=1
    down+=a
else:
    down=1900+a
    
#print(up,down)
ok=0
for i in range(k-1):
    a,b=map(int,input().split())
    if b==2:
        if up>1899:
            inf=1
            up=1899
        if down>1899 :
            ok=1
            break
        up+=a
        down+=a
    else:
        if up<1900:
            ok=1
            break
        if down<1900:
            down=1900
        up+=a
        down+=a
    #print(up,down)
if inf==0 and ok==0:
    ok=1
    print("Infinity")
elif ok==0:
    print(up)
else:
    print("Impossible")