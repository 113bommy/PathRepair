n = int(input())
for i in range(n):
    a = list(map(int, input().split()))
    n1 = a[0]
    x = a[1]
    t = a[2]
    c = t // x
    if n1 < c:
        d = (n1) * (n1 - 1) // 2
    else:
        d = (c ) * (c - 1) // 2 + (n1 - c) * c
    
    print(d)
    
        