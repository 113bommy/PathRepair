n,k=map(int,input().split())
r=list(range(n))
index=1;
if k>=0 and k<n:
    while k<n-1:
        if k+2<=n-1:
            r[index]=index+1
            r[index+1]=index
            index=index+2
            k=k+2
        elif k+1==n-1:
            r[index]=0
            r[0]=index;
            k=k+1
            break
        else:
            break
    for i in r:
        print(i+1,end=' ')
else:
    print(-1)
