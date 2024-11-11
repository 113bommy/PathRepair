l,r=map(int,input().split())
if r-l<2:
    print("-1")
else:
    if r-l==2:
        if l%2==0:
            print(l,end=" ")
            print(l+1,end=" ")
            print(l+2)
        else:
            print("-1")
    else:
        if l%2==0:
            print(l,end=" ")
            print(l+1,end=" ")
            print(l+2)
        else:
            print(l+1, end=" ")
            print(l + 2, end=" ")
            print(l + 3)