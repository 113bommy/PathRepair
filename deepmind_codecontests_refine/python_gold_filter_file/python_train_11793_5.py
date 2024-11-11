from math import sin,pi
n,R,r = map(int,input().split())
if R==2*r:
    if n<3:
        print("YES")
    else:
        print("NO")
elif R<2*r or n==1:
    if n==1 and R>=r:
        print("YES")
    else:
        print("NO")
else:
    x = sin(pi/n)*(R-r)
    if abs(r-x)<pow(10,-15):
        print("YES")
    elif r<=x:
        print("YES")
    else:
        print("NO")