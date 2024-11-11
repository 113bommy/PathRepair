n, m, k, l = map(int, input().split())
if (k+l+m-1)//m*m > n:
    print(-1)
else:
    print((k+l+m-1)//m)
