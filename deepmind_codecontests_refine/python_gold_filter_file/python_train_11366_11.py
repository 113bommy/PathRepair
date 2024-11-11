import math
a,b,n=map(int,input().split())
i=0
while n>0:
    n-=math.gcd(n,(a,b)[i])
    i=1-i
print(1-i)