for _ in range(int(input())):
    n=int(input())
    a =list(map(int,input().split()))
    mx=0
    cur=0
    for i in range(0,n-1,2):
        cur+=a[i+1]-a[i]
        cur=max(0,cur)
        mx=max(cur,mx)
    cur=0
    for i in range(1,n-1,2):
        cur+=a[i]-a[i+1]
        cur=max(0,cur)
        mx=max(cur,mx)
    s=0
    for i in range(0,n,2):
        s+=a[i]
    print(s+mx)