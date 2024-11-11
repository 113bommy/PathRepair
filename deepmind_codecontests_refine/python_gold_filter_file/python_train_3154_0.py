#n=int(input())
for y in range(int(input())):
    #n,m=map(int,input().split())
    #lst1=list(map(int,input().split()))
    n=int(input())
    lst=list(map(int,input().split()))
    dif=[0]*(n-1)
    for i in range(n-2,-1,-1):
        dif[i]=abs(lst[i]-lst[i+1])
    summ=sum(dif)
    minn=100000000000000001
    for i in range(n):
        if i==0:
            minn=min(minn,summ-dif[0])
        elif i==n-1:
            minn=min(minn,summ-dif[-1])
        else:
            minn=min(minn,summ-dif[i-1]-dif[i]+abs(lst[i-1]-lst[i+1]))
    print(minn)