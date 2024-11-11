n,m,k=input().split()
import math
n=int(n)
m=int(m)
k=int(k)
if k+1<=n:
    print(k+1,1)
else:
    n0=n
    n=n-(k-n)//(m-1)
    if n%2==0:
        if (k-n0+1)%(m-1)==0:
            m=m
        else:
            m=(k-n0+1)%(m-1)+1
    else:
        if (k-n0+1)%(m-1)==0:
            m=2
        else:
            m=m+1-(k-n0+1)%(m-1)
    print(n,m)
