n=int(input())
l=list(map(int,input().split()))


if n<3:
    print('-1')
else:
    v=[]
    w=[]
    for i in range(n):
        w.append(l[i])
    
    c=0
    for (i)in range(n-1):
        b=l[i]
        
    
        for j in range(i+1,n):
            if l[j]<b:
                
                b=l[j]
                
                c=j
                
        if l[i]>b:
            
          d=l[i]
          l[i]=l[c]
          l[c]=d
          
    for i in range(n):
       for j in range(n):
           if l[i]==w[j]:
               
               v.append(j)
               w[j]=0
               break
            
            

           
    
    e=False

    for k in range(n-2):
        for j in range(k+1,n-1):
          
          for i in range(j+1,n):
              p=l[k]+l[j]
              
              if p==l[i]:
                  e=True
                  a=v[i]
                  b=v[j]
                  c=v[k]
                  
                  break
              elif p<l[i]:
                  break
              if e==True :
                 break
          if e==True:
               break
        if e==True:
           break

           
    if e==True:
        print(a+1,b+1,c+1)
        
        
    else:
        print(-1)
