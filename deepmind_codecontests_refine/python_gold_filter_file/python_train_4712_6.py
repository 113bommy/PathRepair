for _ in range(int(input())):
    n,k = map(int,input().split())
    a = sorted(list(map(int,input().split())),reverse=True)
    ans=0
    len=1
    for i in range(n):
        if a[i]*len>=k:
            ans+=1
            len=0
        len+=1
    print(ans)
