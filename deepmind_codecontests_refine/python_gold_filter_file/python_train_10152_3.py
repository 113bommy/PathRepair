import math
lrk=[int(i) for i in input().split()]
l=lrk[0]
r=lrk[1]
k=lrk[2]
a=math.ceil(math.log(l,k))
b=round(math.log(r,k))

c=[]
for i in range(a,b+1):
    c.append(k**i)
d=[]
for i in c:
    if(i<=r and i>=l):
        d.append(i)
    
if len(d):
    for i in d:
        print(i,end=" ")
else:
    print(-1)