l,r,x,y = [int(i) for i in input().split()]
from math import gcd,sqrt
c=0
k = y//x
for i in range(1,int(sqrt(k))+1):
    j = k//i
    if j*x>=l and j*x<=r and i*x>=l and i*x<=r and y//x==y/x:
        g =gcd(i,j)
        if g==1 and i*j==k:
            if i==j: 
                #print(i,j)
                c+=1
            else:
                c+=2
print(c)