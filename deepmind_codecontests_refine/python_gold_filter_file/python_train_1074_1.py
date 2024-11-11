n=int(input())
import math
r=list(map(int,input().split()))
d=0
b=0
r.sort()
for i in range(n):
    if i%2==0:
        d+=(r[i]**2)
    else:
        b+=(r[i]**2)
print(abs((d*math.pi)-(b*math.pi)))
    