import math
#q=int(input())
q=1
for _ in range(q):
    n=int(input())
    #a,b=map(int,input().split())
    l=list(map(int,input().split()))
    a=[0]*(10**6)
    m=[]
    for i in range(n):
        m.append(l[i]-i)
    for i in range(n):
        a[m[i]]+=l[i]
    print(max(a))    
        