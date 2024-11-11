from math import log
from collections import deque
n,k=map(int,input().split())
s=list(map(int,input().split()))
ans=0
s.sort()
s1=deque(s)
for j in range(11):
    d=dict()
    z=10**j
    for i in s:
        y=i*z
        u=y%k
        if u in d:
            d[u]+=1
        else:
            d.update({u:1})
    aux=0
    for i in s1:
        y=i
        lg=int(log(i,10))+1
        lg=10**lg
        if lg==z:
            aux1=(y*z)%k
            aux2=y%k
            d[aux1]-=1
            x=(k-aux2)
            if aux2==0:
                x=0
            if x in d:
                ans+=d[x]
            d[aux1]+=1
            aux+=1
        else:
            break
    for i in range(aux):
        s1.popleft()     
print(ans)
