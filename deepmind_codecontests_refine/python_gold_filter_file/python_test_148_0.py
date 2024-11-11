for u in range(int(input())):
    w, h = map(int, input().split())
    a, b, c, d = list(map(int, input().split())), list(map(int, input().split())), list(map(int, input().split())), list(map(int, input().split()))
    a, b, c, d = a[1:len(a)], b[1:len(b)], c[1:len(c)], d[1:len(d)]
    a.sort()
    b.sort()
    c.sort()
    d.sort()
    print(max((a[-1] - a[0]) * h, (b[-1] - b[0]) * h, (c[-1] - c[0]) * w, (d[-1] - d[0]) * w))