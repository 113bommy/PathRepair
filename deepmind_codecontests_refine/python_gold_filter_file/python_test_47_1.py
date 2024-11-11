for _ in range(int(input())):
    n,k=map(int,input().split())
    x=list(map(int,input().split()))
    xp=[]
    xn=[]
    for i in range(n):
        if x[i]>=0:
            xp.append(x[i])
        else:
            xn.append(abs(x[i]))
    xp.sort()
    xn.sort()
    xp=[0]+xp
    xn=[0]+xn
    
    pn=len(xp)
    nn=len(xn)
    ans1=0
    ans2=0
    if pn>1:
        if (pn-1)%k==0:
            ans1=sum(xp[:pn:k])*2-xp[-1]
        else:
            rem=(pn-1)%k
            ans1=sum(xp[rem:pn:k])*2-xp[-1]
    #print(xp)
    #print(ans1)
    if nn>1:
        if (nn-1)%k==0:
            ans2=sum(xn[:nn:k])*2-xn[-1]
        else:
            rem=(nn-1)%k
            ans2=sum(xn[rem:nn:k])*2-xn[-1]    
    #print(xn)
    #print(ans2)
    ans=ans1+ans2
    ans+=min(xp[-1],xn[-1])
    print(ans)
