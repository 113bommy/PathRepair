for _ in range(int(input())):
    a,b,p=map(int,input().split())
    lst=list(input())
    l=len(lst)-2
    if lst[l]=='A':
        if a>p:
            print(l+2)
            continue
    else:
        if b>p:
            print(l+2)
            continue
    temp=lst[l]
    if temp=='A':
        p-=a
    else:
        p-=b
    l-=1
    while l>=0:
        if lst[l]!=temp:
            temp=lst[l]
            if temp=='A':
                if a>p:
                    break
                else:
                    p-=a
            else:
                if b>p:
                    break
                else:
                    p-=b
        l-=1
    print(l+2)
