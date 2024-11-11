import math
p=math.pi
n=int(input())
r=list(map(int,input().split()))
r.sort()
c=1
a=0
for i in range(n-1,-1,-1):
    if c==1:
        a=a+p*r[i]*r[i]
        c=-1
    else:
        a=a-p*r[i]*r[i]
        c=1
print(a)