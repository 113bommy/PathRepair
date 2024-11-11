import math
inf=10**5

import sys
for _ in range(int(input())):
    n,k=(list(map(int,sys.stdin.readline().split())))
    s='$' + sys.stdin.readline().split("\n")[0]
    r=[0 for i in range(n+1)]
    g=[0 for i in range(n+1)]
    b=[0 for i in range(n+1)]
    
    for i in range(1,n+1):
        if s[i]=='R':
            r[i]=r[max(0,i-3)] + 1
        else:
            r[i]=r[max(0,i-3)] 
        if s[i]=='G':
            g[i]=g[max(0,i-3)] + 1
        else:
            g[i]=g[max(0,i-3)] 
        if s[i]=='B':
            b[i]=b[max(0,i-3)] + 1
        else:
            b[i]=b[max(0,i-3)] 
    
    # print(r)
    # print(g)
    # print(b)
    
    
    def check(i,k):
        m=10**12
        rr=0;gg=0;bb=0
        if k%3==1:
            rr=1
        if k%3==2:
            rr=1
            gg=1
        kk=k
        m=min(m, k//3 + rr -(  r[i + ((k-1)//3)*3  ] - r[max(i-3,0)]) +  k//3 + gg -(  g[i +1+ ((k-2)//3)*3 ] - g[max(i-2,0)]) + k//3  -(  b[i +2+ ((k-3)//3)*3 ] - b[max(i-1,0)]))
        # print(m, k//3 + rr -(  r[i + ((k-1)//3)*3  ] - r[max(i-3,0)]),k//3 + gg -(  g[i + 1 + ((k-2)//3)*3 ] - g[max(i-2,0)]),k//3  -(  b[i + 2 +((k-3)//3)*3 ] - b[max(i-1,0)]))
        
        m=min(m, k//3 + rr -(  g[i + ((k-1)//3)*3 ] - g[max(i-3,0)]) +  k//3 + gg -(  b[i + 1 +    ((k-2)//3)*3 ] - b[max(i-2,0)]) + k//3  -(  r[i + 2+((k-3)//3)*3 ] - r[max(i-1,0)]))
        # print(m, k//3 + rr -(  g[i + ((k-1)//3)*3  ] - g[max(i-3,0)]),k//3 + gg -(  b[i +1+ ((k-2)//3)*3 ] - b[max(i-2,0)]),k//3  -(  r[i+2 + ((k-3)//3)*3 ] - r[max(i-1,0)]))
        
        m=min(m, k//3 + rr -(  b[i + ((k-1)//3)*3 ] - b[max(i-3,0)]) +  k//3 + gg -(  r[i +1+ ((k-2)//3)*3 ] - r[max(i-2,0)]) + k//3  -(  g[i +2+ ((k-3)//3)*3 ] - g[max(i-1,0)]))
        # print(m, k//3 + rr -(  b[i + ((k-1)//3)*3  ] - b[max(i-3,0)]),k//3 + gg -(  r[i +1+ ((k-2)//3)*3 ] - r[max(i-2,0)]),k//3  -(  g[i +2+ ((k-3)//3)*3 ] - g[max(i-1,0)]))
        return m    
    m=10**13    
    for i in range(n-k+1):
        # print("i",i)
        m=min(m,check(i+1,k))
    print(max(m,0))
    
            

    