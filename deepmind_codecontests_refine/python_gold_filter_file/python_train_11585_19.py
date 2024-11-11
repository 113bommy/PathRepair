for t in range(int(input())):
    a,b=map(int,input().split())
    if a==b:
        print(0)
    elif b>a:
        if (b-a)%2:
            print(1)
        else:
            print(2)
    else:
        if (a-b)%2:
            print(2)
        else:
            print(1)