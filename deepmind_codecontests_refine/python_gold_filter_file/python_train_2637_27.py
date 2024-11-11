import math
n=int(input())
w=0
a1=0
a2=0
a3=0
a4=0
if n>0:
    x=input().split()
    for i in x:
        m=int(i)
        if m==1:
            a1=a1+1
        if m==2:
            a2=a2+1
        if m==3:
            a3=a3+1
        if m==4:
            a4=a4+1
w=w+a4+a3
if a2%2==0:
    w=w+a2/2
    if a3>=a1:
        w=w
    else:
        w=w+math.ceil((a1-a3)/4)
else:
    w=w+a2//2+1
    a1=a1-2
    if a3>=a1:
        w=w
    else:
        w=w+math.ceil((a1-a3)/4)
print(int(w))