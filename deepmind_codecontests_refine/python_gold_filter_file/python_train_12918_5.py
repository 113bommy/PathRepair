n,k=map(int,input().split())
a=list(map(int,input().split()))
if k==1:
    print(max(a))
    print(n)
else:
    b=[]
    u=int()
    cnt=int()
    for i in range(k):
        u=max(a)
        cnt+=u
        b.append(a.index(u))
        a[b[i]]=0
    b.sort()
    print(cnt)
    print(b[0]+1,end=' ')
    for i in range(1,k-1):
        print(b[i]-b[i-1],end=' ')
    print(n-b[k-2]-1)
