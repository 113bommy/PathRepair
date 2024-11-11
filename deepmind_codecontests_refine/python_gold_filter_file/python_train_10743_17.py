q=int(input())
for t in range(q):
    n,m=map(int,input().split())
    a=list(map(int,input().split()))
    ans=[]
    an=0
    b=[]
    for i in range(n-1):
        ans.append([i+1,i+2])
        an+=a[i]+a[i+1]
        b.append([a[i],i+1])
    ans.append([1,n])
    an+=a[0]+a[n-1]
    b.append([a[n-1],n])
    b.sort()
    if len(ans)>m or n==2:
        print(-1)
    else:

        for i in range(m-len(ans)):
            ans.append([b[0][1],b[1][1]])
            an+=b[0][0]+b[1][0]
        print(an)
        for i in range(len(ans)):
            print(*ans[i])