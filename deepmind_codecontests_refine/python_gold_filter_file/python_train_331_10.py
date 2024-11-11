import math
x=int(input())
v=[]
k = math.ceil(math.sqrt(x))
for i in range(1,k+1):
    if(x%i == 0):
        v.append(i)
ans=9999999999999
flag=0
for i in range(len(v)):
    lcm=(v[i]*(x//v[i]))//math.gcd(v[i],x//v[i])
    if(lcm == x):
        res=max(v[i],x//v[i])
        if(res < ans):
            flag=1
            ans=res
            p1=v[i]
            p2=(x//v[i])
if(flag):
    print(p1,p2)
else:
    print(1,x)