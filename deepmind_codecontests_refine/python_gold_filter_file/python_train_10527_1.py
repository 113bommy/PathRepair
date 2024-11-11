n,k=map(int,input().split())
mn=1000000000
for i in range(min(k-1,n),0,-1):
    if n%i==0:
        temp=n//i
        tt=temp*k
        tt+=i
        if tt <mn:
            mn=tt
            
print(mn)