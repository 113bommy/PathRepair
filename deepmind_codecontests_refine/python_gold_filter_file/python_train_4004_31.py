import sys
from math import *
from fractions import gcd
readints=lambda:map(int, input().strip('\n').split())


a,b,c=readints()
st = set()

def sumdigits(x):
    res=0
    while x>0:
        res += x%10
        x=x//10
    return res


for sd in range(82):
    x=b*(sd**a) + c
    if sumdigits(x)==sd and x>0 and x<10**9:
        st.add(x)


buf = ''
res=list(st)
res.sort()
for x in res:
    buf=buf+str(x)+' '
print(len(st))
if len(st)>0:
    print(buf)
