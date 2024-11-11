n, m, d = map(int, input().split())
if d == 0:
    print((m-1)/n)
else:
    print((m-1)*(n-d)*2/n**2)
