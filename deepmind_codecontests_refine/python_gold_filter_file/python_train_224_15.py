m = int(input())
for i in range(m):
    n = int(input())
    c = 10000000000
    d = 0
    for j in range(n):
        a, b = map(int, input().split())
        if b < c:
            c = b
        if a > d:
            d = a
    if c > d:
        print(0)
    else:
        print(d - c)
        
