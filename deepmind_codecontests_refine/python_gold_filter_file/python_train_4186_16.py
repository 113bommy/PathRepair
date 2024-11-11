t=int(input())
for i in range(0,t):
    n=int(input())
    s=input()
    k=list(s)
    l=n//2
    b=[]
    if(k.count('1')==0):
        print(n)
    elif((k.count('0')==1)or((k.count('1')==1)and(k.index('1')==0))):
        print(n*2)

    else:
        for j in range(0,l):
            if(k[j]=='1'):
                f=(n-j)*2
                b.append(f)
        for j in range(l,n):
            if(k[j]=='1'):
                f=(j+1)*2
                b.append(f)
        print(max(b))
        


            
        
    
        
    
