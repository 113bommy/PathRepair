import math
#n,m=map(int,input().split())
from collections import Counter
#for i in range(n):
import math
#for _ in range(int(input())):
#n = int(input())
r1,c1,r2,c2=map(int,input().split())
if r1==r2 or c1==c2:
    a=1
else:
    a=2
if (r1+c1)%2!=(r2+c2)%2:
    b=0
else:
    if r1 + c1 == r2 + c2 or r1 - c1 == r2 - c2:
        b = 1
    else:
        b = 2
c=max(abs(r1-r2),abs(c1-c2))
print(a, b ,c)

