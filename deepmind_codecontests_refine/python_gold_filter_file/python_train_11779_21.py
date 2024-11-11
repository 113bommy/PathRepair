x,y,z=list(map(int,input("").split()))
a,b,c=list(map(int,input("").split()))
counta=0
countb=0
if(x<=a):
    counta=a-x
    if(y<=counta+b):
        countb=counta+b-y
        if(z<=countb+c):
            print("YES")
        else:
            print("NO")

    else:
        print("NO")
else:
    print("NO")
