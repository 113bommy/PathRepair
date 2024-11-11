a,b=list(map(int,input().split()))


if b>a/2:
    if b-1>0:
        print(b-1)
    else:
        print(1)
elif b<=a/2:
    print(b+1)