for _ in range(int(input())):
    b=int(input())
    l=list(map(int,input().split()))
    mxs=l[0]
    c=0
    for i in range(1,b):
        if l[i]*mxs<0:
            c+=mxs
            mxs=l[i]
        else:
            mxs=max(mxs,l[i])
    print(c+mxs)