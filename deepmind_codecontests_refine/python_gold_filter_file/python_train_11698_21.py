a=0
b=0
success_a=0
success_b=0
for _ in range(int(input())):
    x,t1,t2=map(int,input().split())
    if x==1:
        success_a+=t1
        a+=10
    else:
        success_b+=t1
        b+=10
if success_a>=a//2:
    print("LIVE")
else:
    print("DEAD")
if success_b>=b//2:
    print("LIVE")
else:
    print("DEAD")        
    
        
    
    




        
            
        
            
    
    
            
    
        

    
