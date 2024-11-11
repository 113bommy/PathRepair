t=int(input())
for i in range(0,t):
    n,m=map(int,input().split())
    tt=[]
    ll=[]
    hh=[]
    for j in range(0,n):
        ti,l,h=map(int,input().split())
        tt.append(ti)
        ll.append(l)
        hh.append(h)
    max=m
    min=m
    c=0
    p=0
    for j in range(0,n):
        max=tt[j]-p+max
        min=min-(tt[j]-p)
        if((min>hh[j]) or (max<ll[j])):
            c=1
            break
        else:

            if(min<ll[j]):
                min=ll[j]
            if(max>hh[j]):
                max=hh[j]
        p=tt[j]

    if(c==1):
        print("NO")
    else:
        print("YES")






