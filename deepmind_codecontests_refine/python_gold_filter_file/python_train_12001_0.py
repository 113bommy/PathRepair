t=int(input())
for i in range(t):
    n,k=list(map(int,input().split()))
    a=list(map(int,input().split()))
    m=min(a)
    idx=a.index(m)
    c=0
    for j in range(n):
        if a[j]<k and j!=idx:
            c+=(k-a[j])//m
   
            
    print(c)