n,k=input().split()
n=int(n)
k=int(k)
f=0
F=[]
for i in range(2,n//2+1):
    if(n%i==0):
        while(n%i==0 and f<k-1):
            n=n//i
            f=f+1
            F.append(i)
        if(f==k-1):
            break
if(f==k-1 and n!=1):
    for i in range(0,len(F)):
        print(F[i],end=' ')
    print(n)
else:
    print(-1)
    

            
    

    
    