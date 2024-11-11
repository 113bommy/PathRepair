from math import *
def kamehameha(l,n,pos):
    if n<2:
        return n
    if (pos+1)==(2*l):
        return n%2
    n//=2
    pos//=2
    if l>pos+1:
        l-=(pos+1)
    return kamehameha(l,n,pos)

n,l,r=map(int,input().split())
if n==0:
    print(0)
else:   
    ans=0
    pos=pow(2,floor(log2(n))+1)-1
    for i in range(l,r+1):
        tmp=kamehameha(i,n,pos)
        ans+=tmp
    print(ans)