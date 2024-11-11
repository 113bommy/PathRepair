n,x=map(int,input().split())
s=0
i=1
while i*i<=x:
    if x%i==0 and x//i<=n and i<=n:
##        print(i,x//i)
        if i!=x//i:
            s+=2
        else:
            s+=1
    i+=1
print(s)
    
