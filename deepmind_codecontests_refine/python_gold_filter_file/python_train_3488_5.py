k,a,b=map(int,input().split())
if a>0:
    print(b//k-(a-1)//k)
elif a==0:
    if b==0:
        print(1)
    else:
        print(b//k+1)
else:
    print(b//k+(-a)//k+1)