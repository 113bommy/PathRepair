from math import sqrt
p=int(input())
n=2*p+0.5
log=0
for i in range(1,int(sqrt(n))):
    x=(sqrt(n-(i+0.5)**2)-0.5)
    if int(x)==x:
        log=1
        break
if log==1:
    print("YES")
if log==0:
    print("NO")