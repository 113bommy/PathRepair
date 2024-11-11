for _ in range(int(input())):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    a.sort()
    b.sort()
    for i in range(k):
        if a[i]<b[n-i-1]:
            a[i]=b[n-i-1]
    print(sum(a))
