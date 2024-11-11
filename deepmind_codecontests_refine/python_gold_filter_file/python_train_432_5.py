import math as mt
I=lambda:list(map(int,input().split()))
n,=I()
l=I()
s=sum(l)
d=max(l)
gc=d-l[0]
for i in l[1:]:
    gc=mt.gcd(gc,d-i)
print(((d*n)-s)//gc,gc)