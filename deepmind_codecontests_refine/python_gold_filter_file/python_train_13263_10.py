l=list(map(int,input().split(',')))
d=dict()
l2=[]
for i in l:
    if i not in l2:
        l2.append(i)
l2.sort()


b=0
k=0
for i in range(1,len(l2)):
    if l2[i]-l2[b]!=i-b:
        if b!=i-1:
            print(str(str(l2[b])+'-'+str(l2[i-1])),end=',')
        else:
            print(l2[b],end=',')
        b=i
        k=0
if len(l2)-1!=b:
    print(str(str(l2[b])+'-'+str(l2[len(l2)-1])))
else:
    print(l2[b])
    
    




    
    
    
    
    
    
    
    
    
        
    
    


    
    
    
        
        
            
        
        
            
    
        
        
        
        
