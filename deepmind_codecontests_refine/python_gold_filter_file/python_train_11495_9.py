n=int(input())
a=list(map(int,input().split()))
x=0
y=0
z=0
for i in a:
    if i==25:
        x+=1
    elif i==50:
        if x>0:
            x-=1
            y+=1
        else:
            z=1
            print("NO")
            break
    else:
        if (x>0 and y>0):
            x-=1
            y-=1
        elif x>2:
            x-=3
        else:
            z=1
            print("NO")
            break
if z==0:
    print("YES")