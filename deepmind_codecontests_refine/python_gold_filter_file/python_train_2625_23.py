for _ in range(int(input())):
    n,p,k=map(int,input().split()) 
    a=list(map(int,input().split())) 
    a.sort() 
    if a[0]>p:
        print(0) 
    else:
        p1=p-a[0] 
        p2=p 
        count1=1 
        count2=0 
        t=True
        for i in a[1:]:
            if t:
                if p2>=i:
                    p2-=i  
                    count2+=2 
            else:
                if p1>=i:
                    p1-=i 
                    count1+=2 
            t=not t  
        print(max(count1,count2))
            