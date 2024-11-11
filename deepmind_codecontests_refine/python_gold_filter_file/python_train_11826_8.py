n=int(input())
l=[int(i) for i in input().split()]
#l=[abs(i) for i in l]
l.sort() 
k=l[1]-l[0]
for i in range(2,n):
    k=min(k,abs(l[i]-l[i-1]))
print(k,end=' ')
from collections import defaultdict 
d=defaultdict(int)
ans=0 
for i in l:
    ans=ans+d[k+i]+d[i-k]
    d[i]+=1 
print(ans)