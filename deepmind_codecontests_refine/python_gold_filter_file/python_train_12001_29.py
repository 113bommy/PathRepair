t= int(input())
for _ in range(t):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    a.sort()
    m=0
    for i in range(1,n):
        if a[i]<k:
            m+=int((k-a[i])/a[0])
    print(m)
