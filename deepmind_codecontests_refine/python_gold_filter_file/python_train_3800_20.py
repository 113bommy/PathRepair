n,x=map(int,input().split())
i=2
c=0
if (x>n**2):
   print (0)
elif(x==n**2) or (x==1):
    print (1)
else:
 while(i<=n):
    if (x%i==0) and (x<=i**2):
     if (x==i**2):
         c+=1
     else:
         c+=2
        
    i+=1
    
 print (c)
        
            
            
        
        