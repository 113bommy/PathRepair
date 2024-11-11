m=list(input().split())
a=int(m[0])
b=int(m[1])
c=int(m[2])
from math import floor
sl=""
slc=0

for i in range (1, 81):
    t=b*(i**a)+c
    k=0
    if (t<1)or(t>999999999):
        continue
    kk=str(t)
    for j in range(len(kk)):
        k+=int(kk[j])
    if i==k:
        sl=sl+' '+str(t)
        slc+=1
print(slc)
print(sl[1:])
