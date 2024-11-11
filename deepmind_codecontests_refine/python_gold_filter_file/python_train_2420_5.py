import math
t=int(input())
for i in range(0,t):
    n=int(input())
    a=[]
    for i in range(1,n+1):
        a.append(math.pow(2,i))
    m=int(n/2)
    l=[a[n-1]]
    r=[]
    for i in range(0,m-1):
        l.append(a[i])
    for i in range(m-1,n-1):
        r.append(a[i])

    print(abs(int((sum(l)-sum(r)))))