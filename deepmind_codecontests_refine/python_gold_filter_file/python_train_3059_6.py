import sys
import math

p=int(input())
c=0
for i in range(1,p):
    f=0
    for j in range(1,p-1):
        if(pow(i,j,p)==1):
            f=1
            break
    if(f==0 and (pow(i,p-1,p)==1)):
        c+=1
print(c)
