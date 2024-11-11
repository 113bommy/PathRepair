for _ in range(int(input())):
    n,x=map(int,input().split())
    l=list(map(int,input().split()))
    l.sort()
    l.reverse()
 
    t=0
    p=0
    ctr=0
    
    ctr1=0
    while ctr<n:
        
        ctr1+=1
        p=ctr1*l[ctr]
        if p>=x:
            
            t+=1
            ctr1=0
        ctr+=1
    print(t)