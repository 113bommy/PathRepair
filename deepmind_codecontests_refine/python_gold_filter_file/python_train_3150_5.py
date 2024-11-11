for i in range(int(input())):
    a = input()
    b = int(input())
    c = list(map(int, input().split()))
    d = ''.join(sorted(set(a))[::-1])
    e = [None] * b
    f = []
    g = 0
    while g < len(d):
        h2 = []
        for i2 in range(b):
            h = 0
            for i3 in f:
                h += abs(i2 - i3)
            if h == c[i2] and e[i2] == None:
                h2.append(i2)
        if len(h2) <= a.count(d[g]):
            for i2 in h2:
                e[i2] = d[g]
            f += h2
        g += 1
    print(''.join(e))
