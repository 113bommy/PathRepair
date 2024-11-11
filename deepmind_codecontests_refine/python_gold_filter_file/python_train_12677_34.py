from bisect import *
n,m,k=map(int,input().split())
a=[int(i) for i in input().split()]
b=[int(i) for i in input().split()]
c=[0]
for i in a:
    c+=[c[-1]+i]
d=[0]
for i in b:
    d+=[d[-1]+i]

ans=j=bisect(d,k)-1

for i in range(n+1):
    while c[i]+d[j]>k and c[i]<k:
        j-=1
    if c[i]+d[j]<=k:    
        ans=max(ans,i+j)
print(ans)