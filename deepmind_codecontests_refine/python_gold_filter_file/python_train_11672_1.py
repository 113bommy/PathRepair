[n, m, k, l] = map(int, input().split())
if k+l > n:
    print(-1)
else:
    x = (m+k+l-1)//m
    if x*m <= n:
        print(x)
    else:
        print(-1)