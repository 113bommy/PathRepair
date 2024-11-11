for _ in range(int(input())):
    l=list(map(int,input().split()))
    a=max(l)
    c=min(l)
    b=c
    if l.count(max(l))>=2:
        print("YES")
        print(a,c,c)
    else:
        print("NO")