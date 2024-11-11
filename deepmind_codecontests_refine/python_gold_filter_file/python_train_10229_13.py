for _ in range(int(input())):
    a,b,n=map(int,input().split())
    if a>n or b>n:
        print(0)
        continue
    c=0
    while(a<=n and b<=n):
        p=max(a,b)
        q=min(a,b)
        q+=p
        a=p
        b=q
        c+=1
    print(c)