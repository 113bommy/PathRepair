#python program to find the maximum probabilty

x,y,z=map(int,input().split())
a,b,c=map(int,input().split())

flag1,flag2,flag3=0,0,0

if a>=x:
    a-=x
    flag1=1
    if b>=y:
        b-=y
        flag2=1
    elif b+a>=y:
        b-=y
        a+=b
        b=0
        flag2=1
    if flag2==1 and a+max(b,0)+c>=z:
        flag3=1
        
if flag1==1 and flag2==1 and flag3==1:
    print("YES")
else:
    print("NO")