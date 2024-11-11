for t in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    if(a.count(a[0])==n):
        print(0)
    else:
        cnt=0
        maxm=a[0]
        begin=0
        for i in range(n-1):
            if(a[i]>a[i+1]):
                cnt+=(a[i]-a[i+1])
        print(cnt)

