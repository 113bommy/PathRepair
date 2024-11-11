import sys
import math
import collections
l=[]
for i in range(8):
    l.append(list(input()))
c=0
row=[0]*8
for i in range(8):
    if(l[i]==['B']*8):
        c+=1
        row[i]=1
if(c==8):
    print(c)
else:
    k=row.index(0)
    for j in range(8):
        if(l[k][j]=='B'):
            c+=1
    print(c)