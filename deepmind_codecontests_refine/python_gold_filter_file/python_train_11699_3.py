n,m,k = map(int,input().split())
if m >k and m <= n+k:
    res= 1
    for x in range(k+1):
        res*=(m-x)/(n+k-(x-1))
    print(1-res)
else:
    print(0 if m > n+k else 1)