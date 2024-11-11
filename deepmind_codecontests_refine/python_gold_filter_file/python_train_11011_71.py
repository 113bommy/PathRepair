n,k=map(int, input().split())
a=list(map(int, input().split()))
from itertools import accumulate
for _ in range(min(50,k)):
    new=[0]*n
    for i in range(n):
        j=a[i]
        l=max(0,i-j)
        r=min(n-1,i+j)
        new[l]+=1
        if r+1<n:
            new[r+1]-=1
    new=list(accumulate(new))
    a=new
print(*a)
