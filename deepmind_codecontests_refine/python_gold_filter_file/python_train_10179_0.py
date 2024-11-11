n=int(input())
import math
nn=int(math.sqrt(n))+1
a=[0]*(100*n)
for x in range(1,nn+1):
    for y in range(1,nn+1):
        for z in range(1,nn+1):
            a[(x+y+z)**2-x*y-x*z-y*z]+=1
for i in range(1,n+1):
    print(a[i])