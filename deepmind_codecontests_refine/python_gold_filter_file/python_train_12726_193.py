for f in range(int(input())):
    n,m=map(int,input().split())
    if n<3:
        if n==2:
            print(m)
        else:
            print(0)
    else:
        print(2*m)