import math
t=int(input())
for i in range(0,t):
    n,x=map(int,input().split())
    alist=list(map(int,input().split()))
    c=0
    for j in range(0,n):
        c=c+math.ceil(alist[j]/x)
    s=sum(alist)
    d=math.ceil(s/x)
    print(f'{d} {c}')
    
   