for _ in range(int(input())):
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    res = 0
    m = min(a[2], b[1])
    a[2] -= m
    b[1] -= m
    res += 2*m
    
    m = min(a[1], b[0])
    a[1] -= m
    b[0] -= m
    m = min(a[1], b[1])
    a[1] -= m
    b[1] -= m

    m = min(a[0], b[2])
    a[0] -= m
    b[2] -= m
    m = min(a[2], b[2])
    a[2] -= m
    b[2] -= m

    res -= min(a[1], b[2]) * 2
    print(res)
