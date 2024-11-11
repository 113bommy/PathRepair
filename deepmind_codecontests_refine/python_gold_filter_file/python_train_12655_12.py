n,m=map(int,input().split())
l=list(map(int,input().split()))
l1=['0' for i in range(n) ]
k=0
for i in range(1,n) :
    if l[i]+l[i-1]>=m :
        l1[i]=str(l[i])
        l1[i-1]=str(l[i-1])
    else :
        if l[i]+l[i-1]<m :
            k=k+m-l[i]-l[i-1]
            l[i]=m-l[i-1]
            l1[i]=str(l[i])
            l1[i-1]=str(l[i-1])
if n!=1 :
    print(k)
    print(' '.join(l1))
else :
    print(0)
    print(l[0])
            
