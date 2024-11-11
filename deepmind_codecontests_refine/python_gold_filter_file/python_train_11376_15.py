def good(l1,l2,t1,a,n):
    tk=0.0
    ii=0
    sp1=1
    sp2=1
    jj=n-1
    tkj=0.0
    d1=0.0
    d2=0.0
    fsk=l2
    while (tk<t1 and ii<n):
        tp=(a[ii]-l1)/sp1
        
        tk+=tp
        if (tk>=t1):
            xx=tk-tp
            pp=t1-xx
            d1+=pp*sp1
        elif (tk<t1):
            sp1+=1
            d1+=(a[ii]-l1)
            l1=a[ii]
            
            ii+=1
         
    while (tkj<t1 and jj>=0):
        tp=(l2-a[jj])/sp2
        
        tkj+=tp
        if (tkj>=t1):
            xx=tkj-tp
            pp=t1-xx
            d2+=pp*sp2
        elif (tkj<t1):
            sp2+=1
            d2+=(l2-a[jj])
            l2=a[jj]
            
            jj-=1
    
        
    if (ii==n and tk<t1):
        xps=t1-tk
        d1+=xps*sp1
    if (jj==-1 and tkj<t1):
        xpd=t1-tkj
        d2+=xpd*sp2
        
    
    if (abs(d1-(fsk-d2))<1e-6):
        return 1
    elif fsk-d2-d1>=1e-6:
        return 0
    else:
        return 2
    
    
            
        
        
    
t=int(input())
for i in range(t):
    n,l1=input().strip().split(" ")
    n,l1=[int(n),int(l1)]
    a=list(map(int,input().strip().split(" ")))
    a.sort()
    l=0
    r=l1
    for j in range(500):
        mid=(l+r)/2
        if good(0,l1,mid,a,n)==1:
            l=mid
            print(l)
            break
        
        elif good(0,l1,mid,a,n)==2:
            r=mid
            
        else:
            l=mid
    
            
    
    
        
        
        
