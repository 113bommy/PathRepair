for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    ans=0
    for i in range(0,n,2):
        ans+=a[i]
    s=0
    m=0
    for i in range(0,n-1,2):
        s+=a[i+1]
        s-=a[i]
        m=max(s,m)
        if s<0:
            s=0
    s=0
    for i in range(1,n-1,2):
        s-=a[i+1]
        s+=a[i]
        m=max(m,s)
        if s<0:
            s=0
    print(ans+m)
        