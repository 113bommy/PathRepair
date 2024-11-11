# -*- coding: utf-8 -*-
"""
Created on Sun May 31 22:45:01 2020

@author: taolinlin
"""
t = int(input())
for i in range(t):
    n = int(input())
    a = 0
    b = 0
    while n % 2 == 0:
        n = n / 2
        a += 1
    while n % 3 == 0:
        n = n / 3
        b += 1
    if n == 1 and b >= a:
        print(2*b-a)
    else:
        print(-1)
        
        
        
    
    
        
            
    
        
        
                
            
            
            
            
    
            
                
        
        
    
            
    
        
            
        
    

    
    
    
           
        
        
        
            

        
    
        
    
    
    
