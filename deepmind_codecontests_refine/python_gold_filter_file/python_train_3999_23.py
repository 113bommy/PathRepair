n=int(input())
c=-1
k=0
for i in range(n) :
    a=int(input())
    if c!=-1  and c!=a :
        k=k+1
    c=a
print(k+1)
    
    
      
