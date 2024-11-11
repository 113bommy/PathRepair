

import sys
input=sys.stdin.readline
 
p=998244353
pri=p
fac=[1 for i in range((10**6)+1)]
for i in range(2,len(fac)):
    fac[i]=(fac[i-1]*(i%pri))%pri
def modi(x):
    return (pow(x,p-2,p))%p;
    
def ncr(n,r):
    x=(fac[n]*((modi(fac[r])%p)*(modi(fac[n-r])%p))%p)%p
    return x;


n,m=map(int,input().split())
if(n==2):
    print(0)
    exit(0)

if(n==3):

    print((m*(m-1)//2)%pri)
    exit(0)
way=0
for i in range(1,m+1):

    less=i-1

    if(less-1<n-3):
        continue;
    

    way+=ncr(less,1)*ncr(less-1,n-3)*pow(2,n-3,pri)

print(way%p)




    
    
