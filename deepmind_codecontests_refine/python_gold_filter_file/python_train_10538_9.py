import math
#q=int(input())
q=1
for _ in range(q):
    n,m,p=map(int,input().split())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    x=-1 
    for i in range(n):
        if a[i]%p!=0:
            x=i
            break
    for i in range(m):
        if b[i]%p!=0:
            x+=i
            break
    print(x)    