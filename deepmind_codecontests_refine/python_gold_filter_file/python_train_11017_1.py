n,*a=map(int,open(0).read().split())
ans=[]
if sum(t for t in a if t>0)>sum(-t for t in a if t<0):
    i=0
    while a[i]<0:i+=1
    for j in range(n):
        if a[j]>0and i!=j:
            a[i]+=a[j]
            ans+=[(j+1,i+1)]
    for j in range(n):
        if a[j]<0:
            a[j]+=a[i]
            ans+=[(i+1,j+1)]
    for i in range(1,n):
        ans+=[(i,i+1)]
else:
    i=0
    while a[i]>0:i+=1
    for j in range(n):
        if a[j]<0and i!=j:
            a[i]+=a[j]
            ans+=[(j+1,i+1)]
    for j in range(n):
        if a[j]>0:
            a[j]+=a[i]
            ans+=[(i+1,j+1)]
    for i in range(n,1,-1):
        ans+=[(i,i-1)]
print(len(ans))
for t in ans:print(*t)