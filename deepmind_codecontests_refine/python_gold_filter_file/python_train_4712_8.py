for _ in range(int(input())):
    n,x=map(int,input().split())
    a=[int(x) for x in input().split()]
    a.sort()
    fr=1
    ans=0
    
    for i in range(n-1,-1,-1):
        if a[i]*fr>=x:
            ans+=1
            fr=1
        else:
            fr+=1
    
    print(ans)