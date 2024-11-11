import math
n=int(input())
p=int(math.sqrt(n))
for x in range(p,n+1):
    if(x*p>=n):
        print (2*(x+p))
        break