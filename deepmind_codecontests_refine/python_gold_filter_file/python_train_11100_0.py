n,k=map(int,input().split())
a=list(map(int,input().split()))
if k>=n:
    print(max(a))
else:
    for i in range(k-1):
        a.append(a[i])
    if max(a[0:k+1])==a[0]:
            print(a[0])
    else:
        i=a.index(max(a[0:k+1]))
        while True:
            ma=max(a[i:i+k])
            if ma==a[i]:
                print(ma)
                break
            else:
                i=a.index(ma)
