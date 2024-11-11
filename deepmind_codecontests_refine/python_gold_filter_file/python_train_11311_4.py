import math
n,m=(int(i) for i in input().split())
while(n!=0 and m!=0 and ((n>=m and n>=2*m) or (m>n and m>=2*n))):
    if(n>=m):
        n%=(2*m)
    else:
        m%=(2*n)
print(n,m)