n,k = map(int,input().split())
k-=1
a = list(map(int,input().split()))
se = set(a)
if len(se)==1:
    print(0)
else:
    ind = 0
    prev = a[0]
    for x in range(1,n):
        if a[x]!= prev:
            ind = x
            prev = a[x]

    if k<ind:
        print(-1)
    else:
        print(ind)


