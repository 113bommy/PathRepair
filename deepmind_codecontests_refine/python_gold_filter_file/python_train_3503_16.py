n = int(input())
k = int(input())
a = int(input())
b = int(input())
c=0
while n>1:
    if k>1:
        if n%k==0:
            if (n-n//k)*a<b:
                c+=(n-n//k)*a
            else:
                c+=b
            n//=k
            
        else:
            if n/k>1:
                p=n%k
                n-=p
                c+=a*p
            else:
                p=n%k-1
                n-=p
                c+=a*p
    else:
        c=a*(n-1)
        n=1
print(c)
    


    
                    
    
    
