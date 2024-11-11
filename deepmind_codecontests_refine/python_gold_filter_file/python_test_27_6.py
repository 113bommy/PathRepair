for t in range(int(input())):
    n,m,k = map(int,input().split())
    d,e = (n*(n-1))//2,n-1
    if n==1:
        if (m==0 and k>1):
            print("YES")
        else:
            print("NO")
    elif n==2:
        if (m==1 and k>2):
            print("YES")
        else:
            print("NO")
    else:
        if m>=e and m<=d :
            if d==m :
                if k>2:
                    print("YES")
                else:
                    print("NO")
            else:
                if k>3:
                    print("YES")
                else:
                    print("NO")
        else:
            print("NO")