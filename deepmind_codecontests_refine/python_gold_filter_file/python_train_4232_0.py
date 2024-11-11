n=int(input())
L=[0]*5000
L[0]=1
f=1
for i in range(n) :
    C=input()
    if C=='f' :
        f=f+1
    else :
        for j in range(1,f) :
            L[j]=(L[j]+L[j-1])%1000000007
print(L[f-1])
        
            
        
    
