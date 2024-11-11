for _ in range(int(input())):
    n,p,k=map(int,input().split())
    a=list(map(int,input().split()))
    a.sort()
    l=[0]
    for i in range(k-1):
        l.append(l[-1]+a[i])
    for i in range(k-1,n):
        l.append(l[i-k+1]+a[i])
    ch=0
    #print(l)
    while(ch<=n):
        if l[ch]<=p:
            pos=ch
        ch+=1
    print(pos)