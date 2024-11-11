for _ in range(int(input())):
    a,b,n,s=map(int,input().split())
    k=s//n
    if k<=a:
        j=s%n
        if j<=b:
            print("YES")
        else:
            print("NO")
    else:
        if b>=s-a*n:
            print("YES")
        else:
            print("NO")
