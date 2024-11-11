for _ in range(int(input())):
    n=int(input())
    xor=0
    suma=0
    a=list(map(int,input().strip().split()))
    for i in range(n):    
        xor=xor^a[i]
    suma=sum(a)
    if suma==2*xor:
        print(0)
        print()
    else:
        print(2)
        print(xor,end=" ")
        print(suma+xor)
        
            
    
         
            
        
    
        
    