for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    x=0
    mx=min(a)-1
    for i in range(n):
        if a[i]>mx:
            mx=a[i]
        elif a[i]<mx:
            x=max(x,mx-a[i])
    ans=0
    prd=1
    while x>0:
        x-=prd
        prd=2*prd
        ans+=1
    print(ans)
    