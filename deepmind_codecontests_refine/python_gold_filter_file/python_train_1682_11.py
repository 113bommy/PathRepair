mod = 1000000007
ii = lambda : int(input())
si = lambda : input()
dgl = lambda : list(map(int, input()))
f = lambda : map(int, input().split())
il = lambda : list(map(int, input().split()))
ls = lambda : list(input())
from math import *
n,m=f()
l=il()
l2=[0]*(n-1)
a=il()
for i in range(1,n):
    l2[i-1]=l[i]-l[i-1]
gd=l2[0]
for i in range(n-1):
    gd=gcd(gd,l2[i])
for i in range(m):
    if gd%a[i]==0:
        print('YES')
        exit(print(l[0],i+1))
print('NO')