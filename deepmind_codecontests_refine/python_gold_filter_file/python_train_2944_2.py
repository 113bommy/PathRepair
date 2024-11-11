t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    i = 0
    ans = 0
    while i < n:
        if a[i] == 1:
            ans += 1
        if i + 1 < n and a[i + 1] == 0:
            i += 1
        elif i + 2 < n and a[i + 2] == 1:
            i += 3
        else:
            i += 2
    print(ans)
            
            


  
        
    
    
    
    
            
           
                                
            
            
            
    

    
    
    
