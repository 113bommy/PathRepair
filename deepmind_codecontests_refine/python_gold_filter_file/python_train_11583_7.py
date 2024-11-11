for _ in range(int(input())):
    n,k=map(int,input().split())
    s=input()
    l=[]
    for i in range(n):
        if s[i]=="1":
            l.append(i+1)
    if len(l)==0:
        c=0
        for i in range(0,n,k+1):
            c+=1
        print(c)
    else:
        ans=0
        if (l[0] - 1) >= k+1:
            ans += (l[0]- 1) // (k + 1)
        for i in range(1,len(l)):
            for j in range(l[i-1]+k+1,l[i]-k,k+1):
                ans+=1
        if (n-l[-1] ) >= k+1:
            ans += (n - l[-1] ) // (k + 1)
        print(ans)



