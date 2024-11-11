t=int(input())
while t>0:
    x,y = map(int,input().split())
    if x==y or x>y:
        print("YES")
    elif x==1 or x==3:
        print("NO")
    elif x==2 and y==3:
        print("YES")
    elif x==2 and y>3:
        print("NO")
    else:
        print("YES")
    t-=1
        