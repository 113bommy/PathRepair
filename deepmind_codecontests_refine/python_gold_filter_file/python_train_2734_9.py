t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    if len(a) == 1:
        print('YES')
    else:
        a.sort()
        c = 0
        for i in range(n-1):
            b = a[i+1] - a[i]
            if b > 1:
                c += 1
        if c >= 1:
            print('NO')
        else:
            print('YES')
    
    
        
            
    
    
        
    
        
            
            
            
        
            
            
            
            
            
            

    
        
        
        
        
    
    
        
            
    
        
        
                
            
            
            
            
    
            
                
        
        
    
            
    
        
            
        
    

    
    
    
           
        
        
        
            

        
    
        
    
    
    
