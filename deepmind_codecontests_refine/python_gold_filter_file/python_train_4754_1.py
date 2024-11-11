b=list(map(int,input().split()))
pans=0
for i in range(14):
    a=b.copy()
    if a[i]==0:
        continue
    k=a[i]
    a[i]=0
    for j in range(i+1,14):
        k-=1
        a[j]+=1
    for j in range(14):
        a[j]+=k//14
    k%=14
    for j in range(k):
        a[j]+=1
    ans=0
    for j in range(14):
        if a[j]%2==0:
            ans+=a[j]
    if ans>pans:
        pans=ans
print(pans)
        
    
