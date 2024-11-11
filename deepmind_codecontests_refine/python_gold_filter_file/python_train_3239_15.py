import math
n,m=(int(i) for i in input().split())
m1,m2=0,0
if(m==0):
    print(n,n)
else:
    if(m<math.ceil(n/2)):
        m1=n-(2*m)
    for i in range(1,n+1):
        if(m<=(i*(i-1))//2):
            m2=i
            break
    print(m1,n-m2)