for _ in range(int(input())):
    x,y,n=map(int,input().split())
    if x>n and y!=n:
        print(y)
        continue

    z=n%x
    if z==y:
        print(n)
        continue
    else:
        if z<y:
            print(n-x+(y-z))
            continue
        else:
            print(n-(z-y))
            continue
    
