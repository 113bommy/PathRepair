s=input()
n=len(s)
if n==1:
    print('Mike')
else:
    m=s[0]   
    for i in range(n):
        if s[i]>m:
            print('Ann')
        else:
            m=s[i]
            print('Mike')
            
    
    
    
    
    
    

    
    
                
