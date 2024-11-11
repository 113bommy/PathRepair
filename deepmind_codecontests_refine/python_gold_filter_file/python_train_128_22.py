from math import *
t=int(input())
for _ in range(t):
    n,m=map(int,input().split())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    f=0
    for i in range(m):
        for j in range(n):
            if a[j]==b[i]:
                k=a[j]
                f=1
                break
        if f==1:
            break
    if f==0:
        print('NO')
    else:
        print('YES')
        print(1,k)
    
            
    