for _ in range(int(input())):
    n,x=map(int,input().split())
    l=list(map(int,input().split()))
    l.sort(reverse=True)
    #print(l)
    ans=0
    t=-1
    for i in range(n):
        if(l[i]>=x):
            ans+=1
        else:
            t=i
            break
    if(t==-1):
        print(ans)
    else:
        c=1
        for i in range(t,n):
            if(l[i]*c>=x):
                ans+=1
                c=1
            else:
                c+=1
        print(ans)
