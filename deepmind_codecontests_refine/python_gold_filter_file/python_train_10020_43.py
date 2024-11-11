for _ in range(int(input())):
    n,x=map(int,input().split())
    u=[]
 
    
    
    for i in range(n-1):
        U,V=map(int,input().split())
        
        u.append(U)
        u.append(V)
        
    if u.count(x)<2:
        print("Ayush")
        
    else:
        
        if n%2!=0:
            print("Ashish")
        
        else:
            print("Ayush")