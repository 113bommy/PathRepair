a,b,c = list(map(int,input().split()))
if a!=0:
    k = (b*b) - 4*a*c
    if k<0:
        print(0)
    else:
        a1 = (-b+(k**.5))/(2*a)
        a2 = (-b-(k**.5))/(2*a)
        if a1==a2:
            print(1)
            print(str(a1)+"0"*5)
        if a1!=a2:
            print(2)
            print(str(min(a1,a2))+"0"*5)
            print(str(max(a1,a2))+"0"*5)
else:
    if b!=0:
        k = str((-c)/b)
        print(1)
        print(k+"0"*5)
    else:
        if c==0:
            print(-1)
        else:
            print(0)
