n,k=map(int,input().split())
a=list(map(int, input().split()))

from itertools import accumulate

for _ in range(k):
    imos=[0]*(n+1)
    for i in range(n):
        l=max(0,i-a[i])
        r=min(n,i+a[i]+1)
        imos[l]+=1
        imos[r]-=1
    a=list(accumulate(imos[:n]))
    if a.count(n)==n:
        break
print(*a)
