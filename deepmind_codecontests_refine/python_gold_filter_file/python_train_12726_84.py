for j in range(int(input())):
    n,m=tuple(map(int,input().split()))
    if n==1:
        print(0)
    elif n==2:
        print(m)
    else:
        print(2*m)