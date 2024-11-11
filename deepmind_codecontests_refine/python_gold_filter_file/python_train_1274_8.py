t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))[:n]

    flag1=0
    flag2=0
    s1=0
    s2=0
    d=0
    e=0
    f=0
    g=0
    c1=0
    c2=0
    for j in range(n):
        if flag1==0 and a[j]>0:
            s1+=a[j]
            d=a[j]
            flag1=1
            c1+=1
        elif flag1==1 and a[j]>0:
            if d!=0 and d<a[j]:
                s1=s1+a[j]-d
                d=a[j]
        elif flag1==1 and a[j]<0:
            s1+=a[j]
            e=a[j]
            flag1=0
            c1+=1
        elif flag1==0 and a[j]<0:
            if e!=0 and e<a[j]:
                s1=s1+a[j]
                e*=-1
                s1+=e
                e=a[j]
        if flag2==0 and a[j]<0:
            s2+=a[j]
            f=a[j]
            flag2=1
            c2+=1
        elif flag2==1 and a[j]<0:
            if f!=0 and f<a[j]:
                s2=s2+a[j]
                f*=-1
                s2+=f
                f=a[j]
        elif flag2==1 and a[j]>0:
            s2+=a[j]
            g=a[j]
            flag2=0
            c2+=1
        elif flag2==0 and a[j]>0:
            if g!=0 and g<a[j]:
                s2+=a[j]-g
                g=a[j]
    if c1>c2:
        print(s1)
    elif c2>c1:
        print(s2)
    else:
        print(max(s1,s2))
        
        