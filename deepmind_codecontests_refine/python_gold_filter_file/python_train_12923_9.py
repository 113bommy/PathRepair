from sys import stdin
import math
n,m=map(int,stdin.readline().strip().split())
def trans(n,b):
    s=[]
    while n>=b:
        x=n//b
        s.append(n-x*b)
        n=x
    s.append(n)
    s.reverse()
    return s
d=dict()
def pri(n): 
    while n % 2 == 0:
        if 2 not in d:
            d[2]=1
        else:
            d[2]+=1
        n = n / 2
    for i in range(3,int(math.sqrt(n))+1,2): 

        while n % i== 0:
            if i not in d:
                d[i]=1
            else:
                d[i]+=1
            n = n / i 

    if n > 2:
        if n not in d:
            d[n]=1
        else:
            d[n]+=1
d1=dict()
pri(m)
ans=-1
for i in d:
    d1[i]=0
    x=i
    y=0
    z=i
    while x<=n:
        y+=n//x
        x*=z
    d1[i]=y
    if ans==-1 or (d1[i]//d[i])<ans:
        ans=(d1[i]//d[i])
print(int(ans))
    
        
    
