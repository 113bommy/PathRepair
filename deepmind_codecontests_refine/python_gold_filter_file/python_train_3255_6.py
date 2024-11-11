for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    mi=min(a)
    b=a[:]
    b.sort()
    if b==a:
        print("YES")
    else:
        for i in range(n):
            if a[i]!=b[i]:
                if a[i]%mi:
                    print("NO")
                    break
        else:
            print("YES")
            
            