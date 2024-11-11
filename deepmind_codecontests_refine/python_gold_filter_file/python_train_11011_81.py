n,k=map(int,input().split())
l=list(map(int,input().split()))
from itertools import accumulate
def update(a):
    ret=[0]*len(a)
    for i,x in enumerate(a):
        ret[max(i-x,0)]+=1
        r=min(n-1,i+x)
        if r==n-1:continue
        ret[r+1]-=1
    return list(accumulate(ret))
for i in range(min(50,k)):
    l=update(l)
print(*l)