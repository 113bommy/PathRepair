#YouTube
import sys
sys.setrecursionlimit(10**6)

def kukan(l,r,el=1,er=1):
    em=el+er
    if l+1==r:
        return 0
    if l+2==r:
        return a[l+1]*em
    t=(l,r,el,er)
    if t in memo:
        return memo[t]
    re=10**11
    for m in range(l+1,r):
        tmp=kukan(l,m,el,em)+kukan(m,r,em,er)+a[m]*em
        if tmp<re:
            re=tmp
    memo[t]=re
    return re

n=int(input())
a=list(map(int,input().split()))
memo={}
print(a[0]+kukan(0,n-1)+a[-1])