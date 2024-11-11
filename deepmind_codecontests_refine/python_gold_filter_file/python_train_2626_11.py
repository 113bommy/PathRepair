t=int(input())
while t:
    n,p,k=map(int,input().split())
    l=list(map(int,input().split()))
    l.sort()
    ps=[l[0]]
    for i in range(1,n):
        ps.append(l[i]+ps[i-1])
    pp=p
    cou1=0
    for i in range(1,n,2):
        if(pp>=l[i]):
            pp-=l[i]
            cou1+=2
    if(l[0]<=p):
        pp=p-l[0]
        cou2=1
    else:
        pp=p-l[0]
        cou2=0
    for i in range(2,n,2):
        if(pp>=l[i]):
            pp-=l[i]
            cou2+=2
    print(max(cou1,cou2))
    t-=1