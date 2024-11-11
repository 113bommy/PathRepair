n = int(input())
from math import *
if n==3:
    print(6)
elif n==2:
    print(2)
elif n==1:
    print(1)
else:
    if n%2:
        print(n*(n-1)*(n-2))
    else:
        n-=1
        res = n*(n-1)*(n-2)
        for i in range(n-2,0,-2):
            if gcd(n+1,i)==1:
                res = max(res,(n+1)*n*i)
                break
        print(res)
                