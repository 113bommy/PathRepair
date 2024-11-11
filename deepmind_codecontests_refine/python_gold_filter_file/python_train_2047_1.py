n,m,k = map(int,input().split())
if (k <= n-1):
    print(k+1, 1)
else:
    l = (k - n+1)//(m-1)
    o = (k-n+1)%(m-1)
    x = 0
    if (o == 0):
        x = n - l + 1
    else:
        x = n - l
    y = 0
    if (x%2 == 0):
        if (o == 0):
            y = m
        else:
            y = 1 + o
    else:
        if (o == 0):
            y = 2
        else:
            y = m - o + 1
    print(x,y)
    
