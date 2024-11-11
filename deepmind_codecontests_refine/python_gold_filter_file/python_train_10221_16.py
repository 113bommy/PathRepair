import math
n,m,q=map(int,input().split())
g=math.gcd(n,m)
for i in range(q):
    x1,y1,x2,y2=map(int,input().split())
    
    if x1==1 and x2==1:
        l=n//g
        if (y1-1)//l ==(y2-1)//l :
            print("YES")
        else:
            print("NO")
    elif x1==2 and x2==2:
        l=m//g
        if  (y1-1)//l ==(y2-1)//l :
            print("YES")
        else:
            print("NO")
    elif x1==1 and x2==2:
        l=n//g
        p=m//g
        if (y1-1)//l ==(y2-1)//p :
            print("YES")
        else:
            print("NO")
    else:
        l=n//g
        p=m//g
        if (y1-1)//p ==(y2-1)//l :
            print("YES")
        else:
            print("NO")