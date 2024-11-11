import os,io
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    last=[-1]*(n+1)
    maxdif=[0]*(n+1)
    for i in range(n):
        current=a[i]
        maxdif[current]=max(maxdif[current],i-last[current])
        last[current]=i
    for i in range(1,n+1):
        maxdif[i]=max(maxdif[i],n-last[i])
    ans=[]
    curr=maxdif[1]
    for i in range(1,n+1):
        curr=min(maxdif[i],curr)
        maxdif[i]=curr
    pointer=n
    for i in range(1,n+1):
        if i<maxdif[pointer]:
            ans.append('-1')
        else:
            while maxdif[pointer-1]==i:
                pointer-=1
            ans.append(str(pointer))
    print(' '.join(ans))