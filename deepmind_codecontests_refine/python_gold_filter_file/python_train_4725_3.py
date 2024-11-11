n,k=map(int, input().split())

if(n==1 and k==1):
    print('a')
elif(k>n or k==1):
    print(-1)
elif(k==2):    
    s=""
    if(n%2==0):
        s=['a','b']*(n//2)
    else:
        s=['a','b']*(n//2)
        s.append('a')
    ans="".join(s)    
    print(ans)    
elif(k==n):
    s=""
    for i in range(n):
        s=s+chr(i+97)
    print(s)    
else:
    s=[]
    k=k-2
    rem=n-k
    
    if(rem%2==0):
        s=['a','b']*(rem//2)
    else:
        s=['a','b']*(rem//2)
        s.append('a')
    
    j=0
    
    for i in range(n-k,n):
        s.append(chr(j+99))
        j+=1
    ans="".join(s)    
    
    print(ans)    
        
        
        
        
        
        
        
        
        
        
        
    